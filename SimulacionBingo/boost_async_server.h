#pragma once

#define WIN32_LEAN_AND_MEAN		// Evita que Windows.h y boost/asio.hpp se indefinan, para llamar ShellExecute()

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <thread>
#include <Windows.h>
// #include <shellapi.h>

using boost::asio::ip::tcp;
using namespace std;

static int counter = 0;
static bool *simulacionTerminada = false;
static int *cantJugadores = 0;
static int *cantMaxima = 0;
static int *ultimoNumero = 0;

static string respuestaHTML() {
	stringstream strStream;
	ifstream inFile;
	inFile.open("simulacion.html");//open the input file
	strStream << inFile.rdbuf();//read the file
	inFile.close();
	string str = strStream.str();//str holds the content of the file
	int str_size = str.size();
	std::string header = "HTTP/1.1 200 OK\r\nContent-Length:" + to_string(str_size) + "\r\n\r\n";
	std::string message = header + str;
	counter++;
	return message;
}

static string ajax() {

	// Formato JSON
	stringstream ss;
	ss << "{\"numPila\":" << "\"" << counter << "\"";
	ss << ",";
	ss << "\"end\":" << *(simulacionTerminada);
	ss << ",";
	ss << "\"cantJ\":" << *(cantJugadores);
	ss << ",";
	ss << "\"cantMax\":" << *(cantMaxima);
	ss << ",";
	ss << "\"ult\":" << *(ultimoNumero);
	ss << "}";
	return ss.str();
}

static string respuestaAJAX() {
	std::string header = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";
	std::string message = header + ajax();
	counter++;
	return message;
}

static std::string response() {
	if (counter == 0) {
		return respuestaHTML();
	}
	else {
		return respuestaAJAX();
	}
}

class tcp_connection : public boost::enable_shared_from_this<tcp_connection> {
public:
	typedef boost::shared_ptr<tcp_connection> pointer;

	inline static pointer create(boost::asio::io_service& io_service)
	{
		return pointer(new tcp_connection(io_service));
	}

	inline tcp::socket& socket()
	{
		return socket_;
	}

	inline void start()
	{
		message_ = response();

		boost::asio::async_write(socket_, boost::asio::buffer(message_),
			boost::bind(&tcp_connection::handle_write, shared_from_this(),
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

private:
	inline tcp_connection(boost::asio::io_service& io_service)
		: socket_(io_service)
	{
	}

	inline void handle_write(const boost::system::error_code& /*error*/,
		size_t /*bytes_transferred*/)
	{
	}

	tcp::socket socket_;
	std::string message_;
};

class tcp_server
{
public:
	boost::asio::io_service *myService;
	// static bool simulacionTerminada;

	inline tcp_server(boost::asio::io_service& io_service, bool *simEnd, int *cantJ, int *cantMax, int *ultimoNum)
		: acceptor_(io_service, tcp::endpoint(tcp::v4(), 9001))
	{
		myService = &io_service;
		simulacionTerminada = simEnd;
		cantJugadores = cantJ;
		cantMaxima = cantMax;
		ultimoNumero = ultimoNum;
		start_accept();
	}

private:
	 inline void start_accept()
	{
		// Verificar si el servidor deberia terminar
		if (*(simulacionTerminada) == true) {
			myService->stop();
		}

		tcp_connection::pointer new_connection =
			tcp_connection::create(acceptor_.get_io_service());

		acceptor_.async_accept(new_connection->socket(),
			boost::bind(&tcp_server::handle_accept, this, new_connection,
				boost::asio::placeholders::error));
	}

	inline void handle_accept(tcp_connection::pointer new_connection,
		const boost::system::error_code& error)
	{
		if (!error)
		{
			// cout << "new connection" << endl;
			new_connection->start();
		}

		start_accept();
	}
	
	tcp::acceptor acceptor_;
};