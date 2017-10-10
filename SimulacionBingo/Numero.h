#pragma once
class Numero {
private:
	int valor;
	bool marcado;
public:
	Numero();
	~Numero();

	void setValor(int);
	int getValor();
};

