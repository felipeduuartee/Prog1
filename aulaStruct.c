#include <stdio.h>
#include <string.h>

struct data {

   int dia;
   int mes;
   int ano;

};

struct medicamento {

   char nome[50];
   struct data inicio;

};

struct pacientes {

   char nome[50];
   int idade;
   float peso;
   struct medicamento remedios[3];

};

/* struct pacientes inclusao() {

   struct pacientes paciente;

	strcpy(paciente.nome, "gustavo freshe");
	paciente.idade = 18;
	paciente.peso = 62.6;

	// medicamento 1

	strcpy(paciente.remedios[0].nome, "rivotril");

   	paciente.remedios[0].inicio.dia = 01;
	paciente.remedios[0].inicio.mes = 01;
	paciente.remedios[0].inicio.ano = 2023;

	// medicamento 2

	strcpy(paciente.remedios[1].nome,"gardenal");

	paciente.remedios[1].inicio.dia = 30;
	paciente.remedios[1].inicio.dia = 56;
	paciente.remedios[1].inicio.ano = 2345;


	return paciente;} */


struct pacientes cadastro() {

	int n;
	int i = 1;

	struct pacientes cadastro;
	printf("Digite o nome do paciente: ");
	scanf("%s", cadastro.nome);
	printf("Digite a idade do paciente: ");
	scanf("%d", &cadastro.idade);
	printf("Digite o peso do paciente: ");
	scanf("%f", &cadastro.peso);

	printf("Quantos medicamentos %s está tomando? ", cadastro.nome) ;
	scanf("%d",&n);

	while (i != n) {

	   printf("Digite nome do %d° medicamento: ",i);
	   scanf("%s", cadastro.remedios[i].nome);
	   i++;
	}


	return cadastro;
}
int main() {

	int escolha;
	struct pacientes cadastroPaciente;

	escolha = 0;

	while (escolha != 3) {

	   printf("Voce quer cadastrar ou consultar informações de um paciente?\n");
	   printf("Digite 1 para cadastrar\n");
	   printf("Digite 2 para consultar informações\n");
	   printf("Digite 3 para sair\n");
	   printf("Digite para o que deseja fazer: \t");
	   scanf("%d", &escolha);



	if (escolha == 1)
	 cadastroPaciente = cadastro();
	//if (escolha == 2)
	 //  consultar();
	}
/* struct pacientes internados[15];

	internados[0] = inclusao();
  printf("Paciente = %s \n", internados[0].nome);
  printf("Medicamento1 = %s - Data inicial = %d/%d/%d\n",
	internados[0].remedios[0].nome,
	internados[0].remedios[0].inicio.dia,
	internados[0].remedios[0].inicio.mes,
	internados[0].remedios[0].inicio.ano);
  printf("Medicamento 2 = %s - Data inicial = %d/%d/%d\n",
	internados[1].remedios[1].nome,
	internados[1].remedios[1].inicio.dia,
	internados[1].remedios[1].inicio.mes,
	internados[1].remedios[1].inicio.ano); */

return 0;

}
