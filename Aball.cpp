#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct player
{
    string nume;
    int goluri_p1;
    int goluri_p2;
    int goluri_p3;
}jucatori[8];


int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    string aux_nume;
    char aux_virgula;
    int aux_goluri;

    for(int i=0; i<8; i++)
    {
        f>>aux_nume;
        aux_nume.erase(aux_nume.length()-1,1);
        jucatori[i].nume=aux_nume;

        f>>aux_goluri>>aux_virgula;
        jucatori[i].goluri_p1=aux_goluri;

        f>>aux_goluri>>aux_virgula;
        jucatori[i].goluri_p2=aux_goluri;

        f>>aux_goluri;
        jucatori[i].goluri_p3=aux_goluri;
    }

    int cerinta1=0,cerinta2_scor=0, cerinta3_scor=0;
    string cerinta2_nume="", cerinta3_nume="";
    for(int i=0; i<8; i++)
    {
        cerinta1 += jucatori[i].goluri_p3;
        if(cerinta2_scor<(jucatori[i].goluri_p1 + jucatori[i].goluri_p2 + jucatori[i].goluri_p3))
        {
            cerinta2_nume = jucatori[i].nume;
            cerinta2_scor = jucatori[i].goluri_p1 + jucatori[i].goluri_p2 + jucatori[i].goluri_p3;
        }

        if(cerinta3_scor<(jucatori[i].goluri_p1 + jucatori[i].goluri_p2 *2 + jucatori[i].goluri_p3 *3))
        {
            cerinta3_nume = jucatori[i].nume;
            cerinta3_scor = jucatori[i].goluri_p1 + jucatori[i].goluri_p2 *2 + jucatori[i].goluri_p3 *3;
        }
    }
    int Jets_points=0, Sharks_points=0;
    string cerinta5_nume="",cerinta5_nume_anterior="";
    for(int i=0; i<4; i++)
    {
        Jets_points+= jucatori[i].goluri_p1 + jucatori[i].goluri_p2 *2 + jucatori[i].goluri_p3 *3;
        Sharks_points+= jucatori[i+4].goluri_p1 + jucatori[i+4].goluri_p2 *2 + jucatori[i+4].goluri_p3 *3;
    }


    cout<<cerinta1<<endl;
    cout<<cerinta2_nume<<endl;
    cout<<cerinta3_nume<<endl;
    if(Jets_points<Sharks_points)
    {
        cout<<Sharks_points<<endl;
        int maxi=jucatori[0].goluri_p1 + jucatori[0].goluri_p2 *2 + jucatori[0].goluri_p3 *3, anterior=0;
        cerinta5_nume=jucatori[0].nume;
        for(int i=1; i<4; i++)
        {
            if(maxi < (jucatori[i].goluri_p1 + jucatori[i].goluri_p2 *2 + jucatori[i].goluri_p3 *3))
                anterior=maxi,maxi=jucatori[i].goluri_p1 + jucatori[i].goluri_p2 *2 + jucatori[i].goluri_p3 *3,cerinta5_nume_anterior=cerinta5_nume,cerinta5_nume=jucatori[i].nume;
        }
        cout<<cerinta5_nume_anterior<<endl;
    }
    else
    {
        cout<<Jets_points<<endl;

        int maxi=jucatori[4].goluri_p1 + jucatori[4].goluri_p2 *2 + jucatori[4].goluri_p3 *3, anterior=0;
        cerinta5_nume=jucatori[4].nume;
        for(int i=5; i<8; i++)
        {
            if(maxi < (jucatori[i].goluri_p1 + jucatori[i].goluri_p2 *2 + jucatori[i].goluri_p3 *3))
                anterior=maxi,maxi=jucatori[i].goluri_p1 + jucatori[i].goluri_p2 *2 + jucatori[i].goluri_p3 *3,cerinta5_nume_anterior=cerinta5_nume,cerinta5_nume=jucatori[i].nume;
        }
        cout<<cerinta5_nume_anterior<<endl;
    }


    return 0;
}
