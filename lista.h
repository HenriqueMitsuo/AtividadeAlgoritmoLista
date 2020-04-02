typedef struct Cliente {

    int codigo;
    char nome[20];
    int prioridade;
    struct Cliente *prox;
}C;

//! VARIAVEL DE CONTROLE PARA INSERCAO E REMOCAO NO MEIO DA LISTA
int Controle;

//! INICIA LISTA
void criaLista(C *cabeca);

//! CRIA PACIENTE
C* criaCliente(C *cabeca);

//! INSERÇÃO
void insereInicio(C *cabeca);
void insereMeio(C *cabeca);
void insereFim(C *cabeca);

//! REMOÇÃO
void removeInicio(C *cabeca);
void removeMeio(C *cabeca);
void removeFim(C *cabeca);

//! 
void mostraLista(C *cabeca);

//! MENU
void menu(C *cabeca);