#include<iostream>
#include<string>
#include<vector>
using namespace std;

class siegeSocial {
    string ville;
public:
    siegeSocial(string v) {
        ville = v;
    }
    siegeSocial(const siegeSocial &S) {
        ville = S.ville;
    }
    string get_ville() {
        return ville;
    }
    void set_ville(string v1) {
        ville = v1;
    }
    void afficher() {
        cout << "la ville de siege social est " << ville << "\n";
    }
};

class employee {
    string nom;
public:
    employee() { nom = ""; }
    employee(string name) {
        nom = name;
    }
    employee(const employee &E1) {
        nom = E1.nom;
    }
    string get_employee() {
        return nom;
    }
    void set_employee(string E) {
        nom = E;
    }
    void afficher() {
        cout << "mon nom est " << nom << " je suis content de travailler ici \n";
    }
};

class Entreprise {
    siegeSocial S1;
    vector<employee> tabE;
public:
    Entreprise(string nomVS, vector<employee> tab) : S1(nomVS), tabE(tab) {}

    Entreprise(const Entreprise &E1) : S1(E1.S1), tabE(E1.tabE) {}

    siegeSocial get_siege() {
        return S1;
    }

    void set_siege(siegeSocial S) {
        S1 = S;
    }

    vector<employee> get_staf() {
        return tabE;
    }

    void set_staff(vector<employee> T) {
        tabE = T;
    }

    void recrute(employee A) {
        tabE.push_back(A);
    }

    void afficher() {
        cout << "==siege== \n";
        S1.afficher();
        cout << "employee\n";
        for (int i = 0; i < tabE.size(); i++) {
            tabE[i].afficher();
        }
        cout << "le nombre des employees est " << tabE.size() << "\n";
    }

    void avis_employee(int indice_employee) {
        if (indice_employee >= 0 && indice_employee < tabE.size()) {
            tabE[indice_employee].afficher();
        } else {
            cout << "erreur !!! indice invalide \n";
        }
    }
};

int main() {
    vector<employee> tab;
    tab.push_back(employee("kamal"));
    tab.push_back(employee("badr"));
    tab.push_back(employee("aya"));
    Entreprise T("marrakech", tab);
    T.afficher();

    return 0;
}

