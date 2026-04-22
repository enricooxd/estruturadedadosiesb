#include <stdio.h>
#include "agenda.h"
// incrementa a interface

Agenda criar_agenda(int tamanho)
{
    Agenda agenda;
    agenda.tamanho = tamanho;
    agenda.quantidade = 0;
    return agenda;
}

void adcionar_contato(Agenda *agenda, Contato contato)
{
    if (agenda->tamanho == agenda->quantidade)
    {
        printf("A agenda esta lotada!\n");
        return;
    }

    agenda->contatos[agenda->quantidade] = contato;
    agenda->quantidade++;
}

void listar_contato(Agenda *agenda)
{
    if (agenda->quantidade == 0)
    {
        printf("A agenda esta vazia\n");
        return;
    }

    for (int i = 0; i < agenda->quantidade; i++)
    {
        printf(" %s - %s\n", agenda->contatos[i].nome, agenda->contatos[i].telefone);
    }
}