#include <iostream>
#include <vector> // pour tableaux dynamiques
#include <limits> // pour la fonction read_choice

using namespace std;  /* houla!!! ce using namespace std; avant la fonction
                       * sinon il me balance devant le cout de cette fonction
                       * ceci: error: 'cout' was not declared in this scope */

// moyenneDesValeursEntrees2
// Calcul de la moyenne des valeurs contenues dans un tableau (dynamique)

/* ci-dessous la fonction read_choice qui va servir à filtrer les fantaisies que
* pourrait mettre l'usager; exemple: on lui demande une note sur 20 et il envoie
* 25 ou bien azerty... Pour cette fonction qui va se servir de numeric_limits:
* ajouter en haut include <limits> */
bool read_choice( double & N )
{
  cout << "Entrez une note entre 0 et 20 : " ;
 /* ERROR surprise! 'cout' was not declared in this scope
  * Pourtant je n'ai pas oublié le #include <iostream> !! ?? donc j'ai déclaré !!
  * << est un opérateur de flux (sortant) */
  while ( ! ( cin >> N ) || N < 0 || N > 20 )
     {
      if ( cin.eof() )
        {
	// ^D  (^Z sous windows); Fin du flux d'entree !
	return false;
        }
      else if ( cin.fail() )
        {
         cout << "Saisie incorrecte, c'est pas bien ! recommence : ";
         cin.clear();
         // cin.clear()  c'est pour effacer les bits d'erreurs
         cin.ignore( numeric_limits<streamsize>::max(), '\n' );
         /* cin.ignore ci-dessus pour supprimer la ligne erronée dans le buffer */
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
    double note;
    double moyenne(0);

  /* Demander à l'usager d'entrer une par une les notes; a) pour cela je vais
   * utiliser dès maintenant la fonction read_choice; oui mais cette fonction
   * va ne servir qu'une fois,pour la première note. Le tableau aura donc une
   * taille 1; b) pour que l'usager répète l'opération jusqu'à plus notes, avec
   * des push_back() successifs, va falloir une boucle for : donc a):*/
   if (read_choice(note))
    {
     notesSur20.push_back(note);
     cout << "Tu viens de mettre " << note << " /20"<< endl;
    }
/* Déjà essayer jusqu'ici: oui, ça marche!! on a donc mis une note dans une case
 * du tableau. Passons à la phase b : */
   for(int i(0); i<notesSur20.size(); ++i)
    /* quand cette boucle for va commencer, ce sera avec i(0), la première case
     * et i=0 sera bien inférieur à la taille du tableau qui est déjà 1 */
     {
      // et là, je remets la fonction read_choice:
      if (read_choice(note))
        {
          notesSur20.push_back(note);
          cout << "Tu viens de mettre " << note << " /20"<< endl;
          cout << " Si c'est la dernière note à entrer, tu tapes "
          cin >> machinBool;
             if (machinBool false)
              {
               // tu continues la boucle for donc tu dis quoi ??
              }
              else
               {
                 // la taille du tableau est:
                 // et on calcule la moyenne
               }
        }
      /* cette boucle for fonctionne mais on ne peut pas en sortir... zut !!
       * Comment lui dire que c'est fini ??? Utiliser un bool? ligne 76 */
     }


   return 0;

}

