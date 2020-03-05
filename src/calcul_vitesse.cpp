int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

struct consigne_roues
{
    float rotationDroite;
    float rotationGauche;
};


struct consigne_roues calculVitesse(float angle){
    float rayon=0.05; //rayon de la roue en mètres
    float espace_roues=0.2; //espace entre les deux roues
    float pi=3.141592;
    struct consigne_roues newConsigne;
    float n=espace_roues*angle/(4*pi*rayon);
    newConsigne.rotationDroite=n;
    newConsigne.rotationGauche=-n;
    return newConsigne;

}
