#include <iostream>
#include <vector> // pour tableaux dynamiques
#include <limits> // pour la fonction read_choice

// moyenneDesValeursEntrees2
// Calcul de la moyenne des valeurs contenues dans un tableau (dynamique)
using namespace std;  /*  ce using namespace std; le mettre avant la fonction
                       * sinon il me balance devant le cout de cette fonction
                       * ceci: error: 'cout' was not declared in this scope */

/* ci-dessous la fonction read_choice que le forum de developpez.com m'a
*  conseilléé: elle va servir à filtrer les fantaisies que pourrait mettre
* l'usager; exemple: on lui demande une note sur 20 et il envoie 25 ou bien
* azerty... Pour cette fonction qui va se servir de numeric_limits: ajouter
* en haut include <limits> */
bool read_choice( double & N )
{
  cout << "Entrez une note entre 0 et 20 : " ;
  while ( ! ( cin >> N ) || N < 0 || N > 20 )
     {
      if ( cin.eof() )  // explique-moi
        {

	return false;
        }
      else if ( cin.fail() )
        {
         cout << "Saisie incorrecte, c'est pas bien ! recommence : ";
         // ce qu'il me dit lorsque je tape abcd puis, dessous, ça nettoie
         cin.clear();
         // cin.clear()  c'est pour effacer les bits d'erreurs
         cin.ignore( numeric_limits<streamsize>::max(), '\n' );
         /* cin.ignore ci-dessus pour supprimer la ligne erronée dans le buffer
*/
        }
      else
         {
            cout << "La note n'est pas entre 0 et 20, recommence : ";
         }
     }
    return true;  // succès; la fonction renvoie la note comme il faut
}  // fin de la fonction

// using namespace std; doit être mis avant les fonctions

int main()
{
  // Déclarations des variables dont je vais avoir besoin:
    vector<double> notesSur20; // un tableau vide nommé notesSur20
    int taille; // nombre de copies corrigées =  taille du tableau
    double note;
    double moyenne(0);
    bool ok(true);

 /* Faute d'avoir trouvé  un moyen d'arrêter l'entrée des notes par un bool,
  * vais essayer ainsi: */
    cout << "combien de copies avez-vous corrigées ?  ";
    cin >> taille ;
    // cette variable taille à la place de notesSur20.size dans la boucle for

  /* Demander à l'usager d'entrer une par une les notes:*/
   for(int i(0); i<taille; ++i)
     {
      if (read_choice(note))
        {
          notesSur20.push_back(note);
          cout << "Tu viens de mettre " << note << " /20"<< endl;
          moyenne += notesSur20 [i];     // j'additionne toutes les notes
          cout<< "Vériff des additions: "<< moyenne << endl;
          // là il trouve que 18+12+0 = 6
          moyenne /= taille; /* l'addition dans moyenne est divisée
                              * par la taille du tableau  */
          // là, il trouve que (18+12+0)/3 = 2/20 !! yen a marre! 
        }
  cout << " La moyenne de toutes ces notes est: " << moyenne<<" /20"<< endl;

     }

   return 0;

}
