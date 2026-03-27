#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main(){
    Agenda agenda = criar_agenda(10);

    Contato contato;
    strcpy(contato.nome, "Henri");
    strcpy(contato.telefone, "1111-1111");

    adcionar_contato(&agenda, contato);

    listar_contato(&agenda);

    Contato outro;
    strcpy(outro.nome, "Malu");
    strcpy(outro.telefone, "2222-2222");

    adcionar_contato(&agenda, outro);

    listar_contato(&agenda);


    return 0;
}