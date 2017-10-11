#pragma once
class Numero {
private:
	int valor;
	bool marcado;
public:
	Numero();
	~Numero();
	void setMarcado(bool);
	bool getMarcado();
	void setValor(int);
	int getValor();
};

