typedef int data[3];
typedef enum sexo sexo;
typedef enum estcivil civil;
typedef struct endereco endereco;
typedef struct empregado empregado;
enum sexo {masc, fem};
enum estcivil {solt,cas,viuvo,desq,divorc};
struct endereco {
	char lograd[15], compl[6], bairro[10], cidade[10], 	estado[3], pais[10];
	int numero;
};
struct empregado {
	char nome[20], cargo[10], setor[10];
 	endereco ender; int tel;
	sexo sex; civil estciv;
	data nasc, adm;
	float salario;
};

