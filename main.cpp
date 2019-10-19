#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

vector<char> vector_comun={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


int get_valor_de_letra(char a){
    if(a-'0'<10){
        return a-'0';
    }
    for (int i=0;i<vector_comun.size();i++){
        if (vector_comun[i]==a){
            return i+10;
        }
    }
}

void generate_values(int base,map<int,unsigned long int > &MAP,vector<int> VECTOR){
    unsigned long int temporal=0;
    for(int i=VECTOR.size()-1;i>=0;--i){
        temporal+=(VECTOR[i])*pow(base,VECTOR.size()-i-1);
    }
    MAP[base]=temporal;
}

int main(){
    
    string a,b;
    map<int,unsigned long int> mapaA;
    map<int,unsigned long int> mapaB;
    vector<int> vectorA;
    vector<int> vectorB;
    while (cin>>a>>b){
        if (a=="0" && b=="0"){
            cout<<"0 (base 2) = 0 (base 2)"<<endl;
            continue;
        }
        int maxA=get_valor_de_letra(a[0]);
        int maxB=get_valor_de_letra(b[0]);
        for (int i=0;i<a.length();i++){
            vectorA.push_back(get_valor_de_letra(a[i]));
            if (get_valor_de_letra(a[i])>maxA){
                maxA=get_valor_de_letra(a[i]);
            }
        }
        for (int i=0;i<b.length();i++){
            vectorB.push_back(get_valor_de_letra(b[i]));
            if (get_valor_de_letra(b[i])>maxB){
                maxB=get_valor_de_letra(b[i]);
            }
        }
        /*cout<< "vectorA"<<" ";
        for (int i=0;i<vectorA.size();i++){
            cout<<vectorA[i]<<" ";
        }
        cout<<endl;
        cout<< "vectorB"<<" ";
        for (int i=0;i<vectorB.size();i++){
            cout<<vectorB[i]<<" ";
        }
        cout<<endl;
        */
        for (int i=maxA+1;i<=36;i++){
            generate_values(i,mapaA,vectorA);    
        }
        for (int i=maxB+1;i<=36;i++){
            generate_values(i,mapaB,vectorB);
        }
        /*for( auto it=mapaA.begin();it!=mapaA.end();it++){
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<"MAPA 2 "<<endl;
        for( auto it=mapaB.begin();it!=mapaB.end();it++){
            cout<<it->first<<" "<<it->second<<endl;
        }*/
        
        bool check=true;
        int contador=100;
        int retornoA=0;
        int retornoB=0;
        for (int i=maxA+1;i<=36;i++){
            for (int j=maxB+1;j<=36;j++){
                if (mapaA[i]==mapaB[j] && mapaA[i]!=0 && mapaB[j]!=0 ){
                    unsigned int temporal;
                    if (i>j){
                        temporal=i-j;
                    }else{
                        temporal=j-i;
                    }
                    if(temporal<contador){
                        contador=temporal;
                        retornoA=i;
                        retornoB=j;
                        check=false;
                    }
                    
                    
                }
            }
            
        }
        if(check==true){
            cout<<a<<" is not equal to "<<b<<" in any base 2..36"<<endl;
        }else{
            
            cout<<a<<" (base "<<retornoA<<") = "<<b<<" (base "<<retornoB<<")"<<endl;

        }
    mapaA.clear();
    mapaB.clear();
    vectorA.clear();
    vectorB.clear();
    }
    
    
}
