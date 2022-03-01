/* 336 UVA */
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main(){
    int nc = 0, a, b, i, j, k, n;
    vector<int> LA[30];
    map<int, int> id;
    int visited[30];

    while (cin >> n && n > 0){
        for (int i = 0; i < 30; i++) {
            LA[i].clear();
        }
        int numnodos=0;
        id.clear();
        for (i = 0; i < n; i++) {
            cin >> a >> b;
            if (id.count(a)==0){
                id[a] = numnodos++;
            }
            if (id.count(b)==0){
                id[b] = numnodos++;
            }
            LA[id[a]].push_back(id[b]);
            LA[id[b]].push_back(id[a]);
        }
        cin >> a >> b;
        while (a != 0 || b != 0){
            if (id.count(a)==0){
                id[a] = numnodos++;
            }
            nc++;
            queue<int> q;
            for (int i = 0; i < numnodos; i++) {
                visited[i] = -1;
            }
            k = id[a];
            visited[k] = b;
            q.push(k);
            while (!q.empty()){
                k = q.front();
                q.pop();
                if (visited[k] > 0){
                    for (j = 0; j < LA[k].size(); j++) {
                        if (visited[LA[k][j]] == -1){
                            visited[LA[k][j]] = visited[k]-1;
                            q.push(LA[k][j]);
                        }
                    }
                }
            }
            int ct = 0;
            for (i = 0; i < numnodos; i++) {
                ct += (visited[i] == -1);
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", nc, ct, a, b);
            cin >> a >> b;
        }
    }
    return 0;
}

/* 10127 UVA */
#include <cstdio>

int main()
{
    int n;
    
    while (scanf("%d", &n) == 1)
    {
        int numDigits = 1;
        int value = 1 % n;
        
        while (value)
        {
            ++numDigits;
            value = ((value * 10) + 1) % n;
        }
        
        printf("%d\n", numDigits);
    }
}

/* 11777 UVA */
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    
    int classTests[3];
    
    for (int t = 1; t <= T; ++t)
    {
        int t1, t2, final, attendance;
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &final, &attendance, classTests, classTests + 1, classTests + 2);
        
        // Sorted 0 <= 1 <= 2
        sort(classTests, classTests + 3);
        
        int total = t1 + t2 + final + attendance + (classTests[1] + classTests[2]) / 2;
        char grade;
        
        if (total >= 90)
            grade = 'A';
        else if (total >= 80)
            grade = 'B';
        else if (total >= 70)
            grade = 'C';
        else if (total >= 60)
            grade = 'D';
        else
            grade = 'F';
        
        printf("Case %d: %c\n", t, grade);
    }
}

/* 492 UVA */
#include<iostream>
#include<string>

using namespace std;

int main(){
    string linea;
	string aux = "";
    
    while(getline(cin,linea)){
        for(int i=0; i<linea.size(); i++){
            if((linea.at(i) >= 'A' && linea.at(i) <= 'Z') || (linea.at(i) >= 'a' && linea.at(i) <= 'z')){
            	aux = aux + linea.at(i);
			}
            else{
                if(aux[0] == 'A' || aux[0] == 'E' || aux[0] == 'I' || aux[0] == 'O' || aux[0] == 'U' || aux[0] =='a'
				|| aux[0] == 'e' || aux[0] == 'i' || aux[0] == 'o' || aux[0] == 'u'){
                	cout<<aux<<"ay";
				}else{
                    for(int j=1; j<aux.size(); j++){
                    	cout<<aux.at(j);
					}
                    if(aux != ""){
                    	cout<<aux.at(0)<<"ay";
					}
                }
                aux = "";
                cout<<linea.at(i);
            }
        }
        
        if(aux[0] == 'A' || aux[0] == 'E' || aux[0] == 'I' || aux[0] == 'O' || aux[0] == 'U' || aux[0] =='a'
		|| aux[0] == 'e' || aux[0] == 'i' || aux[0] == 'o' || aux[0] == 'u'){
        	cout<<aux<<"ay";
		} 
        else{
            for(int j=1; j<aux.size(); j++){
            	cout<<aux.at(j);
			}
            if(aux != ""){
                cout<<aux.at(0)<<"ay";
			}
        }
        aux = "";
        cout<<endl;
    }

    return 0;
}

/* 10528 UVA */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	
	string musicKey[12][7] ={{"C", "D", "E", "F", "G", "A", "B"},
							{"C#", "D#", "F", "F#", "G#", "A#", "C"},
							{"D", "E", "F#", "G", "A", "B", "C#"},
							{"D#", "F", "G", "G#", "A#", "C", "D"},
							{"E", "F#", "G#", "A", "B", "C#", "D#"},
							{"F", "G", "A", "A#", "C", "D", "E"},
							{"F#", "G#", "A#", "B", "C#", "D#", "F"},
							{"G", "A", "B", "C", "D", "E", "F#"},
							{"G#", "A#", "C", "C#", "D#", "F", "G"},
							{"A", "B", "C#", "D", "E", "F#", "G#"},
							{"A#", "C", "D", "D#", "F", "G", "A"},
							{"B", "C#", "D#", "E", "F#", "G#", "A#"}};
	
	string keyC[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
	
	string linea;
	getline(cin, linea);
	 
	while(linea != "END"){

		vector<string> x;	
		string aux = "";
		
		for(int i = 0; i < linea.size(); i++){
			if(linea[i] != ' '){
				aux += linea[i];
			}
			else{
				x.push_back(aux);
				aux = "";
			}
		}
		if(aux != ""){
			x.push_back(aux);
		}
		
		int key[12] = {1};
		for(int j = 0; j < 12; j++){
			int check = 0;
			for(int cont = 0; cont < x.size(); cont++){
				for(int u = 0; u < 7; u++){
					if (x[cont] == musicKey[j][u]){
						key[j] = 1;
						check = check + 1;
					}
				}
			}
			if(check != x.size()){
				key[j] = 0;
			}
		}
		bool hue = true;
		for(int h = 0; h < 12; h++){
			if(hue == true){
				if(key[h] == 1){
					cout<<keyC[h];
					hue = false;
				}
			}
			else{
				if(key[h] == 1){
					cout<<" "<<keyC[h];
				}
			}
		}
		cout<<"\n";
		getline(cin, linea);
	}
}

/* 612 UVA */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Cadena{
	private:
		string linea;
		int desorden;
	public:
		Cadena(string l, int d);
		int getDesoreden();
		string getLinea();
};

Cadena::Cadena(string l, int d){
	linea = l;
	desorden = d;
}

int Cadena::getDesoreden(){
	return desorden;
}

string Cadena::getLinea(){
	return linea;
}

int CalcularDesorden(string linea1, int lon2){
	int cont = 0;
	for(int i=0; i<lon2; i++){
		for(int j=i+1; j<lon2; j++){
			if(linea1[i] > linea1[j]){
				cont++;
			}
		}
	}
	return cont;
}

bool Organizar(Cadena a, Cadena b){
	return (a.getDesoreden() < b.getDesoreden());
}

int main(){
	
	int n, espacio = 0;
	cin>>n;
	
	while(n--){
		int lon, can;
		cin>>lon>>can;
		vector<Cadena> DNA;
		
		for(int i=0; i<can; i++){
			string l;
			cin>>l;
			int d = CalcularDesorden(l, lon);
			DNA.push_back(Cadena(l, d));
		}
		
		stable_sort(DNA.begin(), DNA.end(), Organizar);
		
        if(espacio) {
        	cout<<"\n";
		}
        espacio = 1;
        
        for(int i=0; i<can; i++){
        	cout<<DNA[i].getLinea()<<endl;
		}
					
	}
	
	return 0;
}

/* 12085 UVA */
#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	int a;
	int Ntelefonos;
	int contador = 1;
	
	cin>>Ntelefonos;
	while((Ntelefonos != 0)){
		vector<int> numeros;

	    cout<<"Case "<<contador++<<":"<<endl;
	    for (int i = 0; i < Ntelefonos; ++i){
	    	cin>>a;
	    	numeros.push_back(a);
	    	
	    }
	    cin>>Ntelefonos;
	}
	
	return 0;
}

/* 755 UVA */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Numero{
	int num;
	int cont;
	Numero(int num1);
};

Numero::Numero(int num1){
	num = num1;
	cont = 0;
}

int main(){
	
	int casos;
	cin>>casos;
	vector<Numero> directorio;
	bool espacio = false;
	
	while(casos--){
		
		int cant;
		cin>>cant;
		while(cant--){
			string ns;
			cin>> ns;
							
			for(int i=0; i<ns.size(); i++){
				if(ns[i] == 'A' || ns[i] == 'B' || ns[i] == 'C'){
					ns[i] = '2';
				}
				else if(ns[i] == 'D' || ns[i] == 'E' || ns[i] == 'F'){
					ns[i] = '3';
				}
				else if(ns[i] == 'G' || ns[i] == 'H' || ns[i] == 'I'){
					ns[i] = '4';
				}
				else if(ns[i] == 'J' || ns[i] == 'K' || ns[i] == 'L'){
					ns[i] = '5';
				}
				else if(ns[i] == 'M' || ns[i] == 'N' || ns[i] == 'O'){
					ns[i] = '6';
				}
				else if(ns[i] == 'P' || ns[i] == 'R' || ns[i] == 'S'){
					ns[i] = '7';
				}
				else if(ns[i] == 'T' || ns[i] == 'U' || ns[i] == 'V'){
					ns[i] = '8';
				}
				else if(ns[i] == 'W' || ns[i] == 'X' || ns[i] == 'Y'){
					ns[i] = '9';
				}
			}
			
			int lau = atoi(ns.c_str());
			directorio.push_back(Numero(lau));
			
			for(int i=0; i<cant; i++){
				if(directorio[i].num == directorio[i+1].num){
					directorio[i].cont ++;
				}
			}
		}
						
		if(espacio){
			cout<<endl;
		}
		espacio = true;
		
		vector<Numero>::iterator it;
		for(it = directorio.begin(); it != directorio.end(); it++){
        	cout<< it->num << " " << it->cont << endl;
		}
				
	}
	
	return 0;
}

/* 11321 UVA */
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int m;
bool ordenar(int a, int b){
	
	if(a % m != b % m){ 

		return a%m < b%m ;
	}else if(a % m == b % m){

		if( a%2 == 0  && b%2 != 0){ 
				return false;
		}
		else if(a%2 != 0  && b%2 == 0){
			return true;
		}
		else if( a%2 !=0  && b%2 != 0 ){
				return a>b;
		}
		else if( a%2 == 0  && b%2 == 0){	
				return a<b;
		}
	}
	else{
		return false;
	}
}

int main(){
	int n;
	int a;
	
	while(cin >> n >> m){
		vector<int> num;
		cout<<n<<" "<<m<<endl;
		if(n==0 && m==0){
			break;
		}
		for(int i=0; i<n;i++){
			cin>>a;
			num.push_back(a);
		}
		
		sort(num.begin(), num.end(), ordenar);
		
		for (int i = 0; i < n; i++){
			cout<<num[i]<<endl;
		}
		

	}
	
	return 0;

}


/* 10194 UVA */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Team{
	public:
		string name;
		int points, wins, goalDifference, goalsScored, goalsAgainst, games, ties, loses;

		Team(string);
		string getName;
		void setTeam(int, int, int, int, int, int, int, int);		
		bool TeamSortPredicade(const Team& d1, const Team&d2);
};
bool Team::TeamSortPredicade(const Team& d1, const Team&d2){
	if(d1.points > d2.points){
		return d1.points < d2.points;
	}
	if(d1.points == d2.points){
		if(d1.wins > d2.wins){
			return d1.wins > d2.wins;
		}
		if(d1.wins == d2.wins){
			if(d1.goalDifference > d2.goalDifference){
				return d1.goalDifference > d2.goalDifference;
			}
			if(d1.goalDifference == d2.goalDifference){
				if(d1.goalsScored > d2.goalsScored){
					return d1.goalsScored > d2.goalsScored;	
				}
				if(d1.goalsScored == d2.goalsScored){
					if(d1.games < d2.games){
						return d1.games < d2.games;
					}
					if(d1.games == d2.games){
						if(d1.name > d2.name){
							return d1.name > d2.name;
						}
					}
				}
			}
		}
	}
}
Team::Team(string n){
	name = n;
}
void Team::setTeam(int p, int w, int gd, int gs, int ga, int g, int t, int l){
	points =  points + p;
	wins = wins + w;
	goalDifference = goalDifference + gd;
	goalsScored = goalsScored + gs;
	goalsAgainst = goalsAgainst + ga;
	games = games + g;
	ties = ties + t;
	loses = loses + l;
}
int main(){
	int cases;
	cin>>cases;
	for(int i = 0; i < cases; i++){
		string tournament;
		getline(cin, tournament);
		int numTeams;
		cin>>numTeams;
		cin.ignore();
		vector <Team> teams;
		for(int j; j < numTeams; j++){
			string t;
			getline(cin, t);
			teams.push_back(t);
		}
		int tourGames;
		cin>>tourGames;
		cin.ignore();
		for(int k; k < tourGames; k++){
			string gameS;
			getline(cin, gameS);
			vector <string> gameV;
			string aux = "";
			for(int m = 0; m < gameS.size(); m++){
				if(gameS[m] != '#' || gameS[m] != '@'){
					aux += gameS[m];
				}
				else{
					gameV.push_back(aux);
					aux = "";
				}
			}
			if(aux != ""){
				gameV.push_back(aux);
			}
			int gd1, gd2, gs1, gs2;
			gs1 = gameV[1];
			gs2 = gameV[2];
			gd1 = gs1 - gs2;
			gd2 = gs2 - gs1;
			vector<Team>::iterator it1;
			it1 = find(teams.begin(), teams.end(), gameV[0]);
			vector<Team>::iterator it2;
			it2 = find(teams.begin(), teams.end(), gameV[3]);
			if(gs1 > gs2){
				it1.setTeam(3, 1, gd1, gs1, gs2, 1, 0, 0);
				it2.setTeam(0, 0, gd2, gs2, gs1, 1, 0, 1);
			}
			if(gs1 < gs2){
				it2.setTeam(3, 1, gd2, gs2, gs1, 1, 0, 0);
				it1.setTeam(0, 0, gd1, gd1, gd2, 1, 0, 1);
			}
			else{
				it1.setTeam(1, 0, gd1, gs1, gs2, 1, 1, 0);
				it2.setTeam(1, 0, gd2, gs2, gs1, 1, 1, 0);
			}
		}
		cout<<tournament<<"\n";
		std::sort(teams.begin(), teams.end(), TeamSortPredicade);
		int count = 0;
		for(vector<Team>::const_iterator citer = teams.begin(); citer != teams.end(); ++citer){
			count++;
			cout << count << ") " << (*citer).name << " " << (*citer).points << "p, " << (*citer).games << "g ("<< (*citer).wins << "-" << (*citer).ties << "-" << (*citer).loses << "), " << (*citer).goalsDifference << "gd (" << (*citer).goalsScored << "-" << (*citer).goalsAgainst <<  ")"<< endl;
		}
	}
}

/* 12541 UVA */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main(){
	int n;
	
	cin >> n;
	int max = 0;
	int min = 999999;
	vector<string> nombres;
	vector<string>::iterator i1;
	vector<int> edad;
	vector<int>::iterator i2;
	while(n--){
		
		
		string _nombre;
		int _dia, _mes, _anio;

		cin>> _nombre >> _dia >> _mes >> _anio;
		
		nombres.push_back(_nombre);
		int suma;
		suma = _dia + _mes*30 + _anio*365;
		
		edad.push_back(suma);
		
		if(suma > max){max = suma;}
		if(suma < min){min = suma;}
	}

	vector<int>::iterator viejo= find(edad.begin(),edad.end(),max);
	vector<int>::iterator joven=find(edad.begin(),edad.end(),min);
	int maxF = viejo-edad.begin();
	int minF = joven-edad.begin();
	cout << nombres[maxF] << endl;
	cout << nombres[minF] << endl;
}

/* 10420 UVA */
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main(){
	
	int n;
	float comp;
	scanf("%d",&n);
	
	string pais;
	string temp;
	string paises[2000];
	int contador[2000] = {0};
	
	for(int k=0; k<2000; k++){
		paises[k] = " ";
	}
	
	while(n--){
		cin>>pais;
		getline(cin, temp);
		
		for(int i=0;i<2000;i++){
			if(pais == paises[i]){
				contador[i] = contador[i] + 1;
				break;
			}else{
				if(paises[i] == " "){
					paises[i] = pais;
					contador[i] = contador[i] + 1;
					break;
				}
			}
		}
	}
	
	string aux;
	int aux2;
	for(int w=0; w<2000; w++){
		for(int k=0; k<2000-1; k++){
			comp = strcmp(paises[k].c_str(), paises[k+1].c_str());
			if(comp > 0){
	        	aux = paises[k];
	            paises[k] = paises[k+1];
	            paises[k+1] = aux;
	
	            aux2 = contador[k];
	            contador[k] = contador[k+1];
	            contador[k+1] = aux2;
	    	}
		}
	}
	
	for(int k=0; k<2000; k++){
		if(contador[k] > 0){
			cout<<paises[k]<<" "<<contador[k]<<endl;
		}
	}
	
	return 0;
}

/* 10196 UVA */
#include<iostream>
#include<string>

using namespace std;

int main(){
	char tablero[8][8];
	bool casos = true;
	int cont  = 0;
	string men_final = "";
	string men1 = " black king is in check";
	string men2 = " no king is in check";
	string men3 = " white king is in check";
	bool bking = false;
	bool wking = false;
	
	while(casos == true){
		casos = false;
		
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				cin>>tablero[i][j];
			}
		}
		
				
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(tablero[i][j] != '.'){
					casos = true;
				}
			}
		}
		
		if(casos == true){
			cout<<"flag"<<endl;
		}
		//Alfil
		
		for(int i=0, j=0; i<8 && j<8; i++, j++){
			if(tablero[i][j] == 'K'){
				wking = true;
			}else if(tablero[i][j] == 'k'){
				bking = true;
			}else{
				continue;
			}
		}
		
		for(int i=8, j=8; i>=0 && j>=0; i--, j--){
			if(tablero[i][j] == 'K'){
				wking = true;
			}else if(tablero[i][j] == 'k'){
				bking = true;
			}else{
				continue;
			}
		}
		
		for(int i=8, j=0; i>=0 && j<8; i--, j++){
			if(tablero[i][j] == 'K'){
				wking = true;
			}else if(tablero[i][j] == 'k'){
				bking = true;
			}else{
				continue;
			}
		}
		
		for(int i=0, j=8; i<8 && j>=0; i++, j--){
			if(tablero[i][j] == 'K'){
				wking = true;
			}else if(tablero[i][j] == 'k'){
				bking = true;
			}else{
				continue;
			}
		}
		
		//Caballo
		
		for(int i=0, j=0; i<8 && j<0; i++, j++){
		}
		}
		
		
		for(int i=1; i<8; i++){
			for(int j=0; j<8; j++){
				if(tablero[i][j]=='p'){
					if ((tablero[i-1][j+1]!='.' && tablero[i-1][j+1]=='K') || (tablero[i+1][j+1]!='.' && tablero[i][j]=='K')){
						wking=true;
						break;
					}
				}
				if (tablero[i][j]=='r'){
					for (int k = 8-i;k>=0 ; k--){
						if ((tablero[8-k][j]!='.' && tablero[8-k][j]=='K')){
							for (int m = 0; m<8-i ; ++i){
								if (tablero[8-k][j]!='.'){
									wking=true;
								}
								else{
									continue;
								}
							}
						}
					}
					for (int k = 8-(8-i);k>=0 ; k--){
						if ((tablero[k][j]!='.' && tablero[k][j]=='K')){
							for (int m = 0; m<8-(8-i) ; ++i){
								if (tablero[8-k][j]!='.'){
									wking=true;
								}
								else{
									continue;
								}
							}
						}
					}
					for (int l = 8-j;l>=0 ; l--){
						if ((tablero[i][8-l]!='.' && tablero[i][8-l]=='K')){
							for (int m = 0; m<8-j ; ++i){
								if (tablero[i][8-l]!='.'){
									wking=true;
									break;
								}
								else{
									continue;
								}
							}
						}
					}
					for (int l = 8-j;l>=0 ; l--){
						if ((tablero[i][8-l]!='.' && tablero[i][8-l]=='K')){
							for (int m = 0; m<8-(8-l) ; ++i){
								if (tablero[i][8-l]!='.'){
									wking=true;
									break;
								}
								else{
									continue;
								}
							}
						}
					}	
				}
			}	
		}
		//

	cout<<"Game #"<<cont<<": "<<men_final<<"."; 
	
	return 0;
}

/* 11494 UVA */
#include<iostream>
#include<math.h>

using namespace std;

int main(){
	
	int x1, y1, x2, y2;
	
	while(cin >> x1 >> y1 >> x2 >> y2){
		if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0){
			break;
		}
		
		if(x1 == x2 && y1 == y2){
			cout<<"0"<<endl;
		}else{
			if(abs(x1-x2) == abs(y1-y2) || abs(x1-x2) == 0 || abs(y1-y2) == 0){
				cout<<"1"<<endl;
			}else{
				cout<<"2"<<endl;
			}
		}			
	}
	
	return 0;
}

/* 10363 UVA */
#include<iostream>
#include<string>

using namespace std;

int main(){
	
	int n;
	cin>>n;
	
	while(n--){
		bool resultado = true;
		
		char tablero[3][3];
		
		int contO = 0, contX = 0,  win=0;
		
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
            	cin>>tablero[i][j];
        	}
        }
        
		for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
            	if(tablero[i][j] == 'O'){
            		contO = contO + 1;
				}else if(tablero[i][j] == 'X'){
					contX = contX + 1;
				}
			}
        }
        
		if (contX-contO >=2 || contX < contO){
			resultado=false;	
		}
		
		if(tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X'){
    		win+=1;
    		if((contO >= contX)|| (contX < contO || contX-contO >=2)){
				resultado = false;
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X'){
    		win+=1;
    		if((contO >= contX)|| (contX < contO || contX-contO >=2)){
				resultado = false;
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X'){
    		win+=1;
    		if((contO >= contX)|| (contX < contO || contX-contO >=2)){
				resultado = false;
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[2][1] == 'X'){
    		win+=1;
    		if((contO >= contX)|| (contX < contO || contX-contO >=2)){
				resultado = false;
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X'){
			win+=1;
    		if((contO >= contX)|| (contX < contO || contX-contO >=2)){
				resultado = false;	
			}//verificada en udebug
    		else{
    			resultado = true;	
			}
		}
		
		else if(tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X'){
			win+=1;
    		if((contO >= contX)|| (contX < contO || contX-contO >=2)){
				resultado = false;
			}//verificada en udebug
    		else{
    			resultado = true;	
			}
		}
		
		else if(tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X'){
			win+=1;
    		if((contO >= contX)|| (contX < contO || contX-contO >=2)){
				resultado = false;
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X'){
			win+=1;
    		if((contO >= contX)|| (contX < contO || contX-contO >=2)){
				resultado = false;
			}//verificada en udebug
    		else{
    			resultado = true;	
			}
		}
		
		if(tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O'){
			win+=1;
    		if(contX > contO || !(contX-contO >=2) ){
				if (!(contX==contO)){
					resultado = false;	
    			}
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O'){
			win+=1;
    		if((contX > contO) || !(contX-contO >=2) ){
				if (!(contX==contO)){
					resultado = false;
    			}
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O'){
			win+=1;
    		if((contX > contO)  || !(contX-contO >=2)){
				if (!(contX==contO)){
					resultado = false;	
    			}	
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O'){
			win+=1;
    		if((contX > contO) || !(contX-contO >=2)){
				if (!(contX==contO)){
					resultado = false;	
    			}
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O'){
			win+=1;
    		if((contX > contO) || !(contX-contO>=2)){
				if (!(contX==contO)){
					resultado = false;	
    			}
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O'){
			win+=1;
    		if((contX > contO) || !(contX-contO >=2)){
				if (!(contX==contO)){
					resultado = false;
    			}
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O'){
			win+=1;
    		if((contX > contO || !(contX-contO >=2)) ){
    			if (!(contX==contO)){
					resultado = false;	
    			}
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		else if(tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O'){
			win+=1;
    		if((contX > contO) || !(contX-contO >=2) || (contX-contO>=-1)){
				if (!(contX==contO)){
					resultado = false;	
    			}
			}//verificada en udebug
    		else{
    			resultado = true;
			}
		}
		
		if(win>1){
			resultado=false;	
		}
		
        if (resultado == true){
        	cout << "yes\n";
		}else if(resultado==false){
			cout << "no\n";
		}           	
	}
	
	return 0;
}

/* 10528 UVA */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	
	string musicKey[12][7] ={{"C", "D", "E", "F", "G", "A", "B"},
							{"C#", "D#", "F", "F#", "G#", "A#", "C"},
							{"D", "E", "F#", "G", "A", "B", "C#"},
							{"D#", "F", "G", "G#", "A#", "C", "D"},
							{"E", "F#", "G#", "A", "B", "C#", "D#"},
							{"F", "G", "A", "A#", "C", "D", "E"},
							{"F#", "G#", "A#", "B", "C#", "D#", "F"},
							{"G", "A", "B", "C", "D", "E", "F#"},
							{"G#", "A#", "C", "C#", "D#", "F", "G"},
							{"A", "B", "C#", "D", "E", "F#", "G#"},
							{"A#", "C", "D", "D#", "F", "G", "A"},
							{"B", "C#", "D#", "E", "F#", "G#", "A#"}};
	
	string keyC[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
	
	string linea;
	getline(cin, linea);
	 
	while(linea != "END"){

		vector<string> x;	
		string aux = "";
		
		for(int i = 0; i < linea.size(); i++){
			if(linea[i] != ' '){
				aux += linea[i];
			}
			else{
				x.push_back(aux);
				aux = "";
			}
		}
		if(aux != ""){
			x.push_back(aux);
		}
		
		int key[12] = {1};
		for(int j = 0; j < 12; j++){
			int check = 0;
			for(int cont = 0; cont < x.size(); cont++){
				for(int u = 0; u < 7; u++){
					if (x[cont] == musicKey[j][u]){
						key[j] = 1;
						check = check + 1;
					}
				}
			}
			if(check != x.size()){
				key[j] = 0;
			}
		}
		bool hue = true;
		for(int h = 0; h < 12; h++){
			if(hue == true){
				if(key[h] == 1){
					cout<<keyC[h];
					hue = false;
				}
			}
			else{
				if(key[h] == 1){
					cout<<" "<<keyC[h];
				}
			}
		}
		cout<<"\n";
		getline(cin, linea);
	}
}


/* 612 UVA */
#include<iostream>
#include<string>

using namespace std;

int main(){
	
	int n, espacio = 0;
	cin>>n;
	
	while(n--){
		int lon, can;
		cin>>lon>>can;
		
		string *arreglo = new string[can + 1]; 
		int *arreglo_aux = new int[can + 1];
		
		for(int i=0; i<can; i++){
            arreglo[i] = new char[lon + 1];
            cin>>arreglo[i];
            int j = 0;
            arreglo_aux[i] = j;
            for(; j<lon; j++){
                for(int k=j+1; k<lon; k++){
                    if(arreglo[i][j] > arreglo[i][k]){
                    	arreglo_aux[i]++;
					}
                }
            }
        }
                
        int aux;
        string aux2;
        for(int i=0; i<can-1; i++){
        	for(int j=0; j<can-i-1; j++){
        		if(arreglo_aux[j] > arreglo_aux[j+1]){
        			aux = arreglo_aux[j];
            		arreglo_aux[j] = arreglo_aux[j+1];
            		arreglo_aux[j+1] = aux;
            		
            		aux2 = arreglo[j];
            		arreglo[j] = arreglo[j+1];
            		arreglo[j+1] = aux2;
				}
			}
		}
        
        if(espacio) {
        	cout<<"\n";
		}
        espacio = 1;
 
        for(int i = 0; i<can; i++){
        	cout<<arreglo[i]<<"\n";
		}		
	}
	
	return 0;
}

/* 394 UVA */
#include<iostream>
#include<string>

using namespace std;

int main(){
	
    int n, r;
    string nombre_matrices[n];
    int bases[n], tamanios[n], dimensiones[n];
    int direccion_base, tamanio, dimension;
    string nombre;
    cin>>n>>r;
	
	for(int i=0; i<n; i++){
		
		cin	>> nombre >> direccion_base >> tamanio >> dimension;
		
		for(int j=0; j<dimensiones[i]; j++){
						
		}
	}
	
	return 0;
}


/* 12279 UVA*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int numeroCasos, razones, regalo, a, b, k=0;

    a = 0;
    while(scanf("%d", &numeroCasos)){
        k++;
        if(numeroCasos == 0){
            break;
        }
        razones = 0;
        regalo = 0;
        for(a = 0; a < numeroCasos; a++){
            scanf("%d", &b);
            if(b == 0){
                regalo++;
            }
            else{
                razones++;
            }
        }
        b = razones - regalo;
        printf("Case %d: %d\n", k, b);
    }
    return 0;
}

/* 10550 UVA */
#include<stdio.h>

int main(){
	int solf, caso1, caso2, caso3, inicial, sol1, sol2, sol3;
	while(scanf("%d %d %d %d", &inicial, &caso1, &caso2, &caso3)){
		if(inicial == 0 && caso1 == 0 && caso2 == 0 && caso3 == 0)
			break;
		if(inicial < caso1)
			sol1 = 40 - (caso1 - inicial);
		else
			sol1 = inicial - caso1;
		if(caso1 > caso2)
			sol2 = 40 - (caso1 - caso2);
		else
			sol2 = caso2 - caso1;
		if(caso2 < caso3)
			sol3 = 40 - (caso3 - caso2);
		else
			sol3 = caso2 - caso3;
			
		solf = 360 * 3 + (sol1 + sol2 + sol3) * 9;
		printf("%d\n", solf);
	}
	return 0;
}

/* 10050 UVA */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int T,N,P,hi[101];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int i;
		scanf("%d",&P);
		for (i=0; i<P; i++){
            scanf("%d",&hi[i]);
        } 
		int Perdidos=0;
		for ( i= 1; i<=N; i++){
			if (i%7==6 || i%7==0){
				continue;
			}
			int j;
			for (j= 0; j<P; j++){
				if (i%hi[j]==0){		
					Perdidos++;
					break;
				}			
			}		
		}
		printf("%d\n",Perdidos);
		}
}


/* 10963 UVA */
#include<stdio.h>

int main(){
	
	int casos, i, j, columnas, pos_arriba, pos_abajo, diferencia;
	scanf("%d", &casos);
		
	while (casos--){
		scanf("%d", &columnas);
		
		scanf("%d %d", &pos_arriba, &pos_abajo);
		diferencia = pos_arriba - pos_abajo;
		int respuesta = 1;
		
		for(j=0; j<columnas-1; j++){
			scanf("%d %d", &pos_arriba, &pos_abajo);		
			if(diferencia != (pos_arriba - pos_abajo))
				respuesta = 0;
		}
		
		if (respuesta == 1){
			printf("yes\n");
		}else{
			printf("no\n");	
		}
		
		if(casos != 0){
			printf("\n");
		}
	}
	return 0;
}


/* 11683 UVA */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int A,C;
	
	while(scanf("%d %d",&A,&C)){
		if (A!=0 && C!=0){
			int cont=0;
			int X[C];
			int i;
			for ( i= 0; i < C; i++){
				scanf("%d",&X[i]);
			}
			cont=A-X[0];
			for (i= 1; i < C; i++){
				
				if (A-X[i]!=0){
						int on= X[i-1]-X[i];
					if (on>0){
						cont=cont+on;
					}	
				}
			}
			printf("%d\n",cont );	
		}
		else{
			break;
		}
	}
	return 0;
}

/* 11172 UVA */
#include <stdio.h>

int main(){

	int x[100];
	int y[100];
	int e, i;

	scanf("%d\n", &e);

	for(i = 1; i <= e; i++){
		scanf("%d %d\n", &x[i], &y[i]);
	}

	for(i = 1; i <= e; i++){
		if(x[i] > y[i]){
			printf(">\n");
		}else if(x[i] < y[i]){
			printf("<\n");
		}else if(x[i] == y[i]){
			printf("=\n");
		}
	}

	return 0;

}


/* 10300 UVA */

#include<stdio.h>
int main(){
	long long a, t, n, b, c, i, j, s;
	while(scanf(“%lld”, &t) == 1){
		for(i = 0; i < t; i++){
			s=0;
			scanf(“%lld”,&n);
			for(j = 0; j < n; j++){
				scanf(“%lld %lld %lld”, &a, &b, &c);
				s+=a*c;
			}
			printf(“%lldn”, s);
		}
	}
	return 0;
}


/*11078 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int casos, n, max, maxDif, i;
	int estudiantes[100000];

	scanf("%d", &casos);

	while(casos--){
		scanf("%d", &n);

		for(i = 0; i < n; i++)
			scanf("%d", estudiantes + i);

		max = maxDif = -300000;

		for(i = 0; i < n - 1; i++){
			max = (estudiantes[i] > max) ? estudiantes[i] : max;
			maxDif = (max - estudiantes[i + 1] > maxDif) ? max - estudiantes[i + 1] : maxDif;
		}

		printf("%d\n", maxDif);
	}
	
	return 0;
}


/*10050 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int casos, dias, cantHartals, i, j, band, total;
	int hartals[100];

	scanf("%d", &casos);

	while(casos-- > 0){
		i = 0;
		total = 0;
		scanf("%d", &dias);
		scanf("%d", &cantHartals);

		while(i < cantHartals){
			scanf("%d", hartals + i++);
		}

		for(i = 1; i <= dias; i++){
			band = 0;

			if(i % 7 != 6 && i % 7 != 0){
				for(j = 0; j < cantHartals; j++){
					if(i % hartals[j] == 0 ){
						band = 1;
						break;
					}
				}

				if(band)
					total++;
			}
		}

		printf("%d\n", total);
	}

	return 0;
}


/*11340 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void limpiar(char *cadena){
  char *p;
  p = strchr (cadena, '\n');
  if (p)
    *p = '\0';
}

int main(){
	char linea[10001];
	int precios[100];
	char sims[100];
	int casos, caracs, p, lineas, tam, i, j;
	double total;
	char car;

	scanf("%d\n", &casos);

	while(casos-- > 0){
		scanf("%d\n", &caracs);
		total = 0;

		i = 0;
		while(i < caracs){
			scanf("%c %d\n", &car, &p);
			precios[i] = p;
			sims[i] = car;
			i++;
		}

		scanf("%d\n", &lineas);

		while(lineas-- > 0){
			/*memset(linea, 0, 10001);*/
			fgets(linea, 10001, stdin);
			limpiar(linea);
			tam = strlen(linea);

			for(i = 0; i < tam; i++){
				for(j = 0; j < caracs; j++){
					if(sims[j] == linea[i]){
						total += precios[j];
						break;
					}
				}
			}
		}

		printf("%.02f$\n", total/100);
	}

	return 0;
}


/*10340 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	int i, j, tam1, tam2, band;
	char palabra1[100000], palabra2[100000];

	while(scanf("%s %s", palabra1, palabra2) != EOF){
		tam1 = strlen(palabra1);
		tam2 = strlen(palabra2);
		i = j = 0;
		band = 0;

		while(i < tam1){
			while(j < tam2 && palabra1[i] != palabra2[j])
				j++;

			if(j == tam2){
				band = 1;
				break;
			}

			j++;
			i++;
		}

		if(band)
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}


/*12503 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void limpiar(char *cadena){
  char *p;
  p = strchr (cadena, '\n');
  if (p)
    *p = '\0';
}

int main(){
	int casos, ins, pos, i, same;
	char linea[20];
	int instructions[100];

	scanf("%d\n", &casos);

	while(casos-- > 0){
		pos = 0;
		i = 0;
		scanf("%d\n", &ins);

		while(i < ins){
			fgets(linea, 20, stdin);
			limpiar(linea);

			if(strcmp(linea, "LEFT") == 0){
				pos--;
				instructions[i] = -1;
			}
			else if(strcmp(linea, "RIGHT") == 0){
				pos++;
				instructions[i] = -2;
			}
			else{
				same = atoi(linea + 8);
				same--;
				instructions[i] = same;

				while(same != -1 && same != -2)
					same = instructions[same];

				if(same == -1)
					pos--;
				else
					pos++;
			}

			i++;
		}

		printf("%d\n", pos);
	}

	return 0;
}


/*12150 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct carro{
	int id;
	int pos;
}

typedef struct carro Carro;

int compare(const void* a, const void* b){
	Carro* interA = (Carro*) a;
	Carro* interB = (Carro*) b;

	return interA->pos > interB->pos;
}


int main(){
	int n, i, j, aux1, aux2, band;
	Carro carros[10000];

	scanf("%d", n);

	while(n != 0){
		i = 0;
		while(i < n){
			scanf("%d %d", &aux1, &aux2);
			carros[i].id = aux1;
			carros[i].pos = i + 1 + aux2;
			i++;
		}

		qsort(carros, n, sizeof(Carro), compare);

		band = 0;
		for(i = 0; i < n; i++){
			if (carros[i].pos != i + 1){
				band = 1;
				break;
			}
		}

		if(band){
			printf("-1\n");
		}else{
			for(i = 0; i < n; i++){
				if(i != n - 1){
					printf("%d ", carros[i].id);
				}else{
					printf("%d", carros[i].id);
				}
			}
			printf("\n");
		}

	}
	return 0;

}

/*10055 UVA*/
#include <stdio.h>

int main(){
	long long int n1, n2;

	while(scanf("%lld %lld", &n1, &n2) != EOF){
		if(n1 > n2){
			printf("%lld\n", n1-n2);
		}else{
			printf("%lld\n", n2-n1);
		}
	}
	return 0;
}


/* 11875 UVA*/
#include <stdio.h>

int main(){
	int t, i, count = 0;

	scanf("%d", &t);

	while(t--){
		count++;
		int n, ans, m;
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d", &m);
			if(i == n / 2){
				ans = m;
			}
		}
		printf("Case %d: %d\n", count, ans);
	}

	return 0;
}


/*12250 UVA*/
#include <stdio.h>
#include <string.h>

int main(){
	char str[16];
	int i = 1;

	while(scanf("%s", str) != EOF){
		if(str[0] == '#' && str[1] == '\0'){
			break;
		}
		if(strcmp(str,"HELLO") == 0){
			printf("Case %d: ENGLISH\n", i);
		}else if(strcmp(str,"HOLA") == 0){
			printf("Case %d: SPANISH\n", i);
		}else if(strcmp(str,"HALLO") == 0){
			printf("Case %d: GERMAN\n", i);
		}else if(strcmp(str,"BONJOUR") == 0){
			printf("Case %d: FRENCH\n", i);
		}else if(strcmp(str,"CIAO") == 0){
			printf("Case %d: ITALIAN\n", i);
		}else if(strcmp(str,"ZDRAVSTVUJTE") == 0){
			printf("Case %d: RUSSIAN\n", i);
		}else{
			printf("Case %d: UNKNOWN\n", i);
		}
		i++;
	}
	return 0;
}


/*10905 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char nums[50][1000];

int compare(const void* a, const void* b){
	int x = *(int*) a;
	int y = *(int*) b;
	int tamA = strlen(nums[x]);
	int tamB = strlen(nums[y]);
	int i;
	int band = 1;

	for(i = 0; i < tamA && i < tamB; i++){
		if(nums[x][i] > nums[y][i]){
			return -1;
		}
		else if(nums[x][i] < nums[y][i]){
			return 1;
		}
	}

	if(tamA == tamB)
		return 0;
	else if(tamA > tamB)
		return 1;
	else
		return -1;
}

int main(){
	int n, i;
	int pos[50];

	scanf("%d", &n);

	while(n != 0){
		for(i = 0; i < n; i++){
			scanf("%s", nums[i]);
			pos[i] = i;
		}

		qsort(pos, n, sizeof(int), compare);

		for(i = 0; i < n; i++){
			printf("%s", nums[pos[i]]);
		}
		printf("\n");

		scanf("%d", &n);
	}

	return 0;
}


/* Taller 3 Estructuras de Datos*/
/* 12577 UVA*/

#include <stdio.h>
#include <string.h>


int main(){

	int caso = 1;
	char pilgrimage[5];

	scanf("%s", &pilgrimage);

	while(strcmp(pilgrimage, "*") != 0){

		if(strcmp(pilgrimage, "Hajj") == 0){

			printf("Case %d: Hajj-e-Akbar\n", caso++);
		}

		else{
			
			printf("Case %d: Hajj-e-Asghar\n", caso++);
		}

		scanf("%s", &pilgrimage);
	}

	return 0;
}


/* 11727 UVA */

#include <stdio.h>
int main(){
	int n, a, b, c;
	
	scanf("%d", &n);
	
	int cont;

	for(cont = 1; cont <= n; cont++){
		scanf("%d %d %d", &a, &b, &c);
		if(a > b && a > c && b > c){
            printf("Case %d: %d\n", cont, b);
        }else if(a > b && a > c && c > b){
            printf("Case %d: %d\n", cont, c);
        }else if(b > a && b > c && a > c){
            printf("Case %d: %d\n", cont, a);
        }else if(b > a && b > c && c > a){
            printf("Case %d: %d\n", cont, c);
        }else if(c > a && c > b && a > b){
            printf("Case %d: %d\n", cont, a);
        }else if(c > a && c > b && b > a){
            printf("Case %d: %d\n", cont, b);

        }

	}

	return 0;
}


/*12403 UVA*/

#include <stdio.h>
#include <string.h>


int main(){

	int T, k = 0, temp;
	char clave[6];

	scanf("%d", &T);

	while(T--){

		scanf("%s", &clave);

		if(strcmp(clave, "donate") == 0){

			scanf(" %d", &temp);

			k = k + temp;
		}

		else{

			printf("%d\n", k);
		}
	}

	return 0;
}


/*11875 UVA*/

#include <stdio.h>

int main(){
	int i, n, x;
	int cont = 1;

	scanf("%d", &i);


	while(i--){
		scanf("%d", &n);
		int arr[10];
		for(x = 0; x < n; x++){
			scanf("%d", &arr[x]);
			if(x == n/2){
				printf("Case %d: %d\n", cont, arr[x]);
				cont++;
			}
		}
	}
}


/*1237 UVA*/

#include <stdio.h>


int main(){

	int T, D, Q, P, i, j, temp;

	scanf("%d", &T);

	while(T--){
		int L[10000];
		int H[10000];
		char marca[10000][20];

		scanf("%d", &D);

		for(i = 0; i < D; i++){

			scanf("%s %d %d", marca[i], &L[i], &H[i]);
		}

		scanf("%d", &Q);

		for(i = 0; i < Q; i++){
			scanf("%d", &P);
			int contador = 0;

			for(j = 0; j < D; j++){
				if(L[j] <= P && H[j] >= P){
					temp = j;
					contador++;
				}
				if(contador > 1){
					break;
				}
			}

			if(contador == 1){
				printf("%s\n", marca[temp]);
			}else{
				printf("UNDETERMINED\n");
			}
		}

		if(T > 0){
			printf("\n");
		}
	}

	return 0;
}

/*11614 UVA*/

#include <stdio.h>
#include <math.h>

int main(){
	long long guerreros;
	int casos, filas;
	scanf("%d", &casos);
	while(casos--){
		scanf("%lld", &guerreros);
		filas = (-1 + sqrt(1 + 8 * guerreros))/2;
		printf("%d\n", filas);
	}
	return 0;
}


/* Taller 4 Estructuras de Datos*/


/*13216 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
La complejidad de este algoritmo es O(n) puesto que solo hay una acción de repetición (while)
que depende de una sola entrada (t). Como este algoritmo tiene una complijidad O(n) cumple 
con los limites establecidos por la plataforma uva que sería O(n^9).
*/

int main(){

	char n[1001];
	char ultimo[2];
	int t, temp, temp2;

	scanf("%d\n", &t);


	while(t--){

		scanf("%s", &n);

		temp = strlen(n);
		ultimo[0] = n[temp - 1];
		temp2 = atoi(ultimo);

		if(temp2 == 0 && strlen(n) == 1){
			printf("1\n");
		}

		else if(temp2 == 1 && strlen(n) == 1){
			printf("66\n");
		}

		else if(temp2 == 2 || temp2 == 7){
			printf("56\n");
		}

		else if(temp2 == 3 || temp2 == 8){
			printf("96\n");
		}

		else if(temp2 == 4 || temp2 == 9){
			printf("36\n");
		}

		else if(temp2 == 5 || temp2 == 0){
			printf("76\n");
		}
		else if(temp2 == 6 || temp2 == 1){
			printf("16\n");
		}
	}
	return 0;
}


/*11001 UVA*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
La complejidad de este algoritmo es O(n) puesto que solo hay una acción de repetición (while)
que depende de una sola entrada (t). Como este algoritmo tiene una complijidad O(n) cumple 
con los limites establecidos por la plataforma uva que sería O(n^9).
*/

 int main(){
 	int v, vO, cant, i, num,divE;
 	float div;
 	scanf("%d %d", &v, &vO);
 	while (v != 0 && vO != 0){
 		divE = v / (vO * 2);
 		div = (float)v / (vO * 2);
 		if (v <= vO){
 			cant = 0;
 		}
 		else if(v == vO + 1){
 			cant = 1;
 		}

 		else{
 			if(div - divE == 0.5){
 				cant = 0;
 			}

 			else if(div - divE > 0.5){
 				cant = divE + 1;
 			}

 			else if(div - divE < 0.5){
 				cant = divE;
 			}
 		}
 		printf("%d\n", cant);
 		scanf("%d %d", &v, &vO);
 	}
 	
 	return 0;
 }


/*10978 UVA*/
#include <stdio.h>
#include <string.h>

 /*
La complejidad de este algoritmo es O(n^2) puesto hay una acción de repetición (for)
que que se encuentra dentro de otra acción de repetición (for). Como este algoritmo tiene una complijidad O(n^2) no cumple 
con los limites establecidos por la plataforma uva que sería O(n^9).
*/

int main(){
	int n, i, len, j;
	char let[64][64];
	char fra[64][64];
	char *org[64];

	for(i = 0; i < 64; i++){
		org[i] = "?";
	}

	scanf("%d", &n);
	while(n != 0){

		for(i = 0; i < n; i++){
			scanf("%s %s", let[i], fra[i]);
		}

		for(i = 0; i < n; i++){
			len = strlen(fra[i]);
			for(j = 0; j < n; j = (j + 1) % n){
				if(org[j][0] == '?' && --len <= 0){
					break;
				}
				org[j] = let[i];
			}
		}

		for(i = 0; i < n; i++){
			printf((i + 1) < n ? "%s " : "%s\n", org[i]);
		}
		scanf("%d", &n);
	}

	return 0;
}


/*10700 UVA*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
La complejidad de este algoritmo es O(n). Como este algoritmo tiene una complijidad O(n) cumple 
con los limites establecidos por la plataforma uva que sería O(n^9).
*/

int main(){

	int n, i, j, contador, num;
	unsigned long long int max, min, multi, sum;
	char array[25];
	char num2[3];

	scanf("%d\n", &n);

	while(n--){

		scanf("%s", &array);

		max = 1;
		min = 0;
		i = 0;
		contador = 0;
		multi = 1;
		sum = 0;

		while(array[i] != '\0'){

			if(array[i] != '+' && array[i] != '*'){
				num2[contador++] = array[i];
			}

			else{
				num2[contador] = '\0';
				num = atoi(num2);
			}

			if(array[i] == '+'){
				min = min + (num * multi);
				sum = sum + num;
				multi = 1;
				contador = 0;
			}

			if(array[i] == '*'){
				multi = multi * num;
				sum = sum + num;
				max = max * sum;
				contador = 0;
				sum = 0;

			}

			i++;
		}

		num2[contador] = '\0';
		num = atoi(num2);
		sum = sum + num;
		min = min + (num * multi);
		max = max * sum;

		printf("The maximum and minimum are %llu and %llu.\n", max, min);
	}
	return 0;
}


/*102 UVA*/
#include <stdio.h>


int main(){

	int B1, B2, B3, G1, G2, G3, C1, C2, C3;
	int total, i, min, flag; 
	int minBCG, minBGC, minCBG, minCGB, minGBC, minGCB;
	int minimos[6];
	/*
	char combinaciones[6][3] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
	char BCG[3] = {"BCG"};
	char BGC[3] = {"BGC"};
	char CBG[3] = {"CBG"};
	char CGB[3] = {"CGB"};
	char GBC[3] = {"GBC"};
	char GCB[3] = {"GCB"};
	*/

	while(scanf("%d %d %d %d %d %d %d %d %d", &B1, &G1, &C1, &B2, &G2, &C2, &B3, &G3, &C3) != EOF){

		total = B1 + G1 + C1 + B2 + G2 + C2 + B3 + G3 + C3;

		minBCG = total - B1 - C2 - G3;
		minimos[0] = minBCG;
		minBGC = total - B1 - G2 - C3;
		minimos[1] = minBGC;
		minCBG = total - C1 - B2 - G3;
		minimos[2] = minCBG;
		minCGB = total - C1 - G2 - B3;
		minimos[3] = minCGB;
		minGBC = total - G1 - B2 - C3;
		minimos[4] = minGBC;
		minGCB = total - G1 - C2 - B3;
		minimos[5] = minGCB;

		min = minimos[0];

		for(i = 1; i < 6; i++){

			if(minimos[i] < min){

				min = minimos[i];
			}
		}

		flag = 0;

		if(min == minimos[0] && flag == 0){

			printf("BCG %d\n", min);
			flag = 1;
		}

		if(min == minimos[1] && flag == 0){

			printf("BGC %d\n", min);
			flag = 1;
		}

		if(min == minimos[2] && flag == 0){

			printf("CBG %d\n", min);
			flag = 1;
		}

		if(min == minimos[3] && flag == 0){

			printf("CGB %d\n", min);
			flag = 1;
		}

		if(min == minimos[4] && flag == 0){

			printf("GBC %d\n", min);
			flag = 1;
		}

		if(min == minimos[5] && flag == 0){

			printf("GCB %d\n", min);
			flag = 1;
		}
	}

	return 0;
}


/*735 UVA*/

#include <stdio.h>

int base[66] = {0};
int usado[66] = {0};
int tres[61][61][61]; 
int A[1001] = {0};
int B[1001] = {0};

int main(){
	int i, j, k;
    int aux = 0;
    for(i = 0; i < 21; ++ i) {
        for (j = 1; j <= 3; ++ j) {
            if (!usado[i*j]) {
                base[aux ++] = i*j;
                usado[i*j] = 1;
            }
        }
    }
    base[aux ++] = 50;
    for (i = 0; i < aux; ++ i) { 
        for (j = 0; j < aux; ++ j) {
            for ( k = 0; k < aux; ++ k) {
                tres[base[i]][base[j]][base[k]] = base[i] + base[j] + base[k];  
                A[base[i] + base[j] + base[k]] ++;
                if (base[i] <= base[j] && base[j] <= base[k]) {
                    B[base[i] + base[j] + base[k]] ++;
                }
            }
        }
    }  

    int x;
    while (scanf("%d", &x) && x > 0) { 
        if (B[x]) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", x, B[x]);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", x, A[x]);
        } else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", x);
        }
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n"); 
    return 0;
}

/*Taller 5 Estructuras De Datos*/

/*11192 UVA*/

#include<stdio.h>
#include<string.h>
int main(){
    int numCambio, i, pos, j, len;
    char arr[110];
    while(scanf("%d", &numCambio) && numCambio != 0){
        scanf("%s", arr);
        len = strlen(arr) / numCambio;
        pos = 0;
        i = 0;
        while(i < strlen(arr)){
            if(i % len == 0){
                pos++;
                j = 0;
            }
            printf("%c",arr[pos * len - j - 1]);
            j++;
            i++;
        }
        printf("\n");
    }
    return 0;
}




/*12488 UVA*/
#include <stdio.h>

int main(){
	int n, i, j, res, aux1, aux2;
	int inicio[30];
	int final[30];

	while(scanf("%d", &n) != EOF){
		res = 0;

		for(i = 0; i < n; i++){
			scanf("%d", &inicio[i]);
		}

		for(i = 0; i < n; i++){
			scanf("%d", &final[i]);
		}


		for(i = 0; i < n; i++){
			j = i;
			aux1 = final[i];

			while(inicio[j] != final[i]){
				aux2 = inicio[j];
				inicio[j] = aux1;
				aux1 = aux2;
				res++;
				j++;
			}
			inicio[j] = aux1;
		}
		printf("%d\n", res);
	}
	return 0;
}


/*725 UVA*/

#include<stdio.h>

int p[15];

int vef(int a, int b){
    int i;
    if(a > 98765)
        return 0;
    for(i = 0; i < 10; i++){
        p[i] = 0;
    }
    if(b<10000)
        p[0] = 1;
    while(a != 0){
        p[a%10] = 1;
        a /= 10;
    }
    while(b != 0){
        p[b%10] = 1;
        b /= 10;
    }
    int total = 0;
    for (i = 0; i < 10; i++){
        total += p[i];                          
    }
    return total==10;                   
}
int main(){
    int i, n, m = 0;
    while (scanf("%d", &n) == 1 && n > 0){
        if(m>0){
            printf("\n");           
        }       
        m++;
        int f = 1;
        for (i = 1234; i < 99999; i++){
            if (vef(i*n,i)){
                printf("%d / %05d = %d\n", i*n,i,n);  
                f = 0;
            }
        }
        if (f > 0){
            printf("There are no solutions for %d.\n",n);
        }
    }
    return 0;
}

/*457 UVA*/

/*10855 UVA*/

/*471 UVA*/

#include <stdio.h>

int posible(long long int n){
	long long int x = n;
	int cmp[10];
	while(x != 0){
		int a = x % 10;
		cmp[a]++;
		if(cmp[a] > 1){
			return 0;
		}
		x = x / 10;
	}
	return 1;
}

int main(){
	int n;
	long long int a, b, c;
	long long int limite = 9876543210;

	scanf("%d", &n);

	while(n--){
	    scanf("%lld\n", &a);
		for(b = 1;b <= limite;b++){
			c = a * b;
			if(posible(b) == 1 && posible(c) == 1){ 
				printf("%lld / %lld = %lld\n", c, b, a);
			}
		}
		if(n == 0){
			printf("\n");
		}
	}
	return 0;
}


/* Taller 7 Estructuras de Datos */

/* 12515 UVA */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string arr1[1003], arr2[503];
	int a, b, respuesta, limite, tamano, tmp, actual, tmp2, t, k;

	scanf("%d %d", &a, &b);

	for(int i=0;i < a; i++){
		scanf("%s", &arr1[i]);
	}
	for(int i=0;i < b; i++){
		scanf("%s", arr2[i]);
	}
	for(int i = 0; i < b; i++){
		respuesta = -1;
		tmp2 = 1000000000;
		tamano = arr2[i].size();
		j = 0;
		while(j < a){
			
			if(arr1[j].size() < tamano){
				continue;
			}
			
			limite = arr1[j].size() - tamano;
			actual = 1000000000;
			k = 0
			
			while(k <= limite){
			
				tmp = 0;
				t = 0
			
				while(t < tamano){
			
					if(arr1[j][t+k] != arr2[i][t]){
						++tmp;
					}

					t++;
				
				}

				if(tmp > actual){
					actual = tmp;
				}else if(tmp == actual){
					actual = actual;
				}else if(actual > tmp){
					actual = actual;
				}

				k++;

			}
			if(tmp2 > actual){
				tmp2 = actual;
				respuesta = j;
			}

			j++;

		}		
		printf("%d\n", respuesta+1);
	}
	return 0;
}

/* 381 UVA */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct estudiante{
    int numExamenes;
    int notas[10];
    int bonus;
    int faltas;
    double promedioNotas;
    int notaFinal;
} estudiante;

estudiante est[30];


int main() {
    int n, s, t, subirNota, bajarNota;
    float temp, sum, sum1, media, desviacion, res;

     scanf("%d", &n);

    cout << "MAKING THE GRADE OUTPUT" << endl;

    while (n--) {
        scanf("%d %d", &s, &t);

        for(int i= 0; i < s; i++){
            est[i].numExamenes = t;
            for(int j = 0; j < t; j++){
                scanf("%d", &est[i].notas[j]); 
            }
            scanf("%d", &est[i].bonus);
            scanf("%d", &est[i].faltas);
        }

        for(int i = 0; i < s; i++){
	        temp = 0;
	        for(int j = 0; j < est[i].numExamenes; j++){
	            temp += est[i].notas[j];
	        }
	        est[i].promedioNotas = temp / est[i].numExamenes;
	    }

	    sum = 0;
	    for(int i = 0;i < s; i++){
	        sum += est[i].promedioNotas;
	    } 

        media = sum / s;

        sum1 = 0;
	    for(int i = 0; i < s; i++){
	        sum1 += (est[i].promedioNotas - media) * (est[i].promedioNotas - media);
	    }
        desviacion = sqrt(sum1 / s);

        for(int i = 0; i < s; i++) {
	        subirNota = (est[i].bonus / 2) * 3;

	        est[i].promedioNotas += subirNota;
	    }
        for(int i = 0; i < s; i++){
	        if (est[i].promedioNotas >= media + desviacion) {
	            est[i].notaFinal = 4;
	        } else if (est[i].promedioNotas >= media) {
	            est[i].notaFinal = 3;
	        } else if (est[i].promedioNotas >= media - desviacion) {
	            est[i].notaFinal = 2;
	        } else {
	            est[i].notaFinal = 1;
	        }
	    }
        for(int i = 0; i < s; i++) {
	        if (est[i].faltas == 0){
	            if(est[i].notaFinal == 3){
				    est[i].notaFinal = 4;
				}else if(est[i].notaFinal == 2){
				    est[i].notaFinal = 3;
				}else if(est[i].notaFinal == 1){
				    est[i].notaFinal = 2;
				}if(est[i].notaFinal == 0){
				    est[i].notaFinal = 1;
				}
	        }else{
	            bajarNota = est[i].faltas / 4;

	            for(int j = 0; j < bajarNota; j++){
	                if(est[i].notaFinal == 4){
				        est[i].notaFinal = 3;
				    }else if(est[i].notaFinal == 3){
				        est[i].notaFinal = 2;
				    }else if(est[i].notaFinal == 2){
				        est[i].notaFinal = 1;
				    }if(est[i].notaFinal == 1){
				        est[i].notaFinal = 0;
				    }
	            }
	        }
	    }

	    res = 0;

	    for(int i = 0; i < s; i++) {
	        res += est[i].notaFinal;
	    }

        printf("%.1lf\n", res / s);
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}

/*11835 UVA*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	vector<int> res;
	int pos, tc, totalPuntos, puntaje, carros, max;
	int finCarr[110][110];
	int puntos[110];
	int c, p;
	scanf("%d %d", &c, &p);
	while(c != 0 && p != 0){
		for(int i = 0; i < c; i++){
			for (int j = 1; j <= p; j++){
				scanf("%d", &pos);
				finCarr[i][pos-1] = j;
			}
		}
		
		carros = 0;
		scanf("%d", &carros);
		for(int x = 0; x < carros; x++){
			totalPuntos = 0;
			scanf("%d", &totalPuntos);
			for(int i = 0; i < totalPuntos; i++){
				puntaje = 0;
				scanf("%d", &puntaje);
				for(int j = 0; j < c; j++){
					puntos[finCarr[j][i]] += puntaje;
				}
			}
			
			max = -1;
			for(int i = 1;i <= p; i++){
				if(max < puntos[i]){
					res.clear();
					max = puntos[i];
					res.push_back(i);
				}
				else if(max == puntos[i]){
					res.push_back(i);
				}
			}
			printf("%d", res[0]);
			for(int i = 1; i < res.size(); i++){
				printf(" %d", res[i]);
			}
			printf("\n");
		}
		scanf("%d %d", &c, &p);
	}
	return 0;
}

/* 296 UVA */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
 
typedef struct intento {
  int codigo;
  int completo;
  int acierto;
}intento;
 
int main(void)
{
  int n, numIntentos, tam;
  vector<intento> intentos;
  char basura;
 
  cin >> n;
 
  while (n--) {
    intentos.clear();
 
    cin >> numIntentos;
 
    while (numIntentos--) {
      intento llenar;
      cin >> llenar.codigo >> llenar.completo >> basura >> llenar.acierto;
      intentos.push_back(llenar);
    }

    bool flag;

    vector<int> respuesta;
 
    for (int i = 0; i < 10000; i++) {
      tam = intentos.size();
      for (int a = 0; a < tam; a++) {
        
        int c[4] = {0,0,0,0};
        int g[4] = {0,0,0,0};
       
        int counter = 0;
        while (a != 0) {
          c[counter] = a % 10;
          a /= 10;
          counter++;
        }
       
        counter = 0;
        while (intentos[a].codigo != 0) {
          g[counter] = intentos[a].codigo % 10;
          intentos[a].codigo /= 10;
          counter++;
        }
       
        int completo = 0;
       
        for (int x = 0; x < 4; x++) {
          if (c[x] == g[x]) {
            c[x] = g[x] = -1;
            completo++;
          }
        }
       
        int acierto = 0;
       
        for (int z = 0; z < 4; z++) {
          for (int y = 0; y < 4; y++) {
            if (c[z] == g[y] && c[z] != -1) {
              c[z] = g[y] = -1;
              acierto++;
            }
          }
        }
        if (completo != intentos[a].completo || acierto != intentos[a].acierto) {
          flag = false;
        }
      }
      if (flag == true){
        respuesta.push_back(i);
      }
    }
 
    if (respuesta.empty()) {
      cout << "impossible" << endl;
    } else if (respuesta.size() > 1) {
      cout << "indeterminate" << endl;
    } else {
      cout << respuesta[0] << endl;
    }
  }
  return 0;
}


/* Taller 8 Estructuras de Datos*/

/* 11223 UVA */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
	int n;
	cin>>n;
	cin.ignore();
	int cont=1;
	while(n--){
		
		cout<<"Message #"<<cont<<endl;;
		vector<char> mensaje(2000);
		int i;
		for(i= 0 ; i < mensaje.size(); i++ ){
			
			scanf("%c",&mensaje[i]);
			if (mensaje[i]=='\n'){	
				break;
			}
			
			
			}
		for (int i = 0; i < mensaje.size(); ++i){
			if(mensaje[i]=='0')
				break;
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && (mensaje[i+3]==' ' || mensaje[i+3]=='\n')){
				cout<<"S";
				i=i+3;
			}		
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && (mensaje[i+3]==' ' || mensaje[i+3]=='\n')){
				cout<<"O"; 		
				i=i+3;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && (mensaje[i+2]==' ' || mensaje[i+2]=='\n')){
				cout<<"A";
				i+=2;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"B";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='.' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"C";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && (mensaje[i+3]==' ' || mensaje[i+3]=='\n')){
				cout<<"D";
				i+=3;
			}
			else if(mensaje[i]=='.' && (mensaje[i+1]==' ' || mensaje[i+1]=='\n')){
				cout<<"E";
				i+=1;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='.' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"F";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && (mensaje[i+3]==' ' || mensaje[i+3]=='\n')){
				cout<<"G";
				i+=3;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"H";
				i+=4;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && (mensaje[i+2]==' ' || mensaje[i+2]=='\n')){
				cout<<"I";
				i+=2;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"J";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && (mensaje[i+3]==' ' || mensaje[i+3]=='\n')){
				cout<<"K";
				i+=3;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"L";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && (mensaje[i+2]==' ' || mensaje[i+2]=='\n')){
				cout<<"M";
				i+=2;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && (mensaje[i+2]==' ' || mensaje[i+2]=='\n')){
				cout<<"N";
				i+=2;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='.' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"P";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='-' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"Q";
				i+=4;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && (mensaje[i+3]==' ' || mensaje[i+3]=='\n')){
				cout<<"R";
				i+=3;
			}
			else if(mensaje[i]=='-' && (mensaje[i+1]==' ' || mensaje[i+1]=='\n')){
				cout<<"T";
				i+=1;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && (mensaje[i+3]==' ' || mensaje[i+3]=='\n')){
				cout<<"U";
				i+=3;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='-' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"V";
				i+=4;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && (mensaje[i+3]==' ' || mensaje[i+3]=='\n')){
				cout<<"W";
				i+=3;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='-' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"X";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"Y";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && (mensaje[i+4]==' ' || mensaje[i+4]=='\n')){
				cout<<"Z";
				i+=4;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='-' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"0";
				i+=5;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='-' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"1";
				i+=5;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='-' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"2";
				i+=5;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='-' && mensaje[i+4]=='-' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"3";
				i+=5;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='-' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"4";
				i+=5;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"5";
				i+=5;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"6";
				i+=5;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"7";
				i+=5;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='.' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"8";
				i+=5;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"9";
				i+=5;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='-' && mensaje[i+4]=='.' && mensaje[i+5]=='-' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<".";
				i+=6;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='-' && mensaje[i+5]=='-' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<",";
				i+=6;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='.' && mensaje[i+5]=='.' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<"?";
				i+=6;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='-' && mensaje[i+5]=='.' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<"'";
				i+=6;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='.' && mensaje[i+4]=='-' && mensaje[i+5]=='-' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<"!";
				i+=6;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='-' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"/";
				i+=5;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"(";
				i+=5;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='.' && mensaje[i+5]=='-' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<")";
				i+=6;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"&";
				i+=5;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='.' && mensaje[i+4]=='.' && mensaje[i+5]=='.' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<":";
				i+=6;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='.' && mensaje[i+4]=='-' && mensaje[i+5]=='.' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<";";
				i+=6;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='-'  && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"=";
				i+=5;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='-' && mensaje[i+4]=='.' && (mensaje[i+5]==' ' || mensaje[i+5]=='\n')){
				cout<<"+";
				i+=5;
			}
			else if(mensaje[i]=='-' && mensaje[i+1]=='.' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='.' && mensaje[i+5]=='-' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<"-";
				i+=6;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='.' && mensaje[i+2]=='-' && mensaje[i+3]=='-' && mensaje[i+4]=='.' && mensaje[i+5]=='-' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<"_";
				i+=6;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='.' && mensaje[i+3]=='.' && mensaje[i+4]=='-' && mensaje[i+5]=='.' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<"\"";
				i+=6;
			}
			else if(mensaje[i]=='.' && mensaje[i+1]=='-' && mensaje[i+2]=='-' && mensaje[i+3]=='.' && mensaje[i+4]=='-' && mensaje[i+5]=='.' && (mensaje[i+6]==' ' || mensaje[i+6]=='\n')){
				cout<<"@";
				i+=6;
			}
			else if(mensaje[i-1]==' ' && mensaje[i]==' '){
				cout<<" ";
				
			}
		}
		cont++;
		
		if(n!=0){
			cout<<endl<<endl;
		}else{
			cout<<endl;
		}
	}
}

/* 11360 UVA */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int casos, tam, cambios, fila1, fila2;
    string cambioRequerido, tmp;

    int matriz[11][11];
    int tmpMatriz[11][11];

    scanf("%d", &casos);
    for(int i = 1; i <= casos; i++){
        scanf("%d", &tam);
        string entrada = "";

	    for(int x = 0; x < tam; x++){
	        cin >> tmp;
	        entrada += tmp;
	    }

	    int index = 0;
	    for(int x = 0; x < tam; x++){
	        for(int y = 0; y < tam; y++){
	            matriz[x][y] = entrada[index++] - '0';
	        }
	    }

        scanf("%d", &cambios);
        for(int j = 0; j < cambios; j++){
            cin >> cambioRequerido;
            if(cambioRequerido == "inc"){
            	for(int x = 0; x < tam; x++){
            		for(int y = 0; y < tam; y++){
			            matriz[x][y]++;
			            if(matriz[x][y] > 9){
			               matriz[x][y] = 0;
			            }
			        }
               }    
            }else if(cambioRequerido == "dec"){
                for(int x = 0; x < tam; x++){
				    for(int y = 0; y < tam; y++){
				        matriz[x][y]--;
				        if(matriz[x][y] < 0){
				            matriz[x][y] = 9;
				        }
				    }
				}
            }else if(cambioRequerido == "transpose"){
                for(int x = 0; x < tam; x++){
				    for(int y=0; y<tam; y++){
				        tmpMatriz[y][x] = matriz[x][y];
				    }
				}
				for(int x=0; x<tam; x++){
				    for(int y=0; y<tam; y++){
				        matriz[x][y] = tmpMatriz[x][y];
				    }
				}
            }else if(cambioRequerido == "row"){
                scanf("%d %d", &fila1, &fila2);
                for(int x = 0; x < tam; x++){
			        swap(matriz[fila1 - 1][x], matriz[fila2 - 1][x]);
			    }
            }else if(cambioRequerido == "col"){
                scanf("%d %d", &fila1, &fila2);
                for(int x = 0; x < tam; x++){
			        swap(matriz[x][fila1 - 1], matriz[x][fila2 - 1]);
			    }
            }
        }
        printf("Case #%d\n", i);
        for(int x = 0; x < tam; x++){
        	for(int y = 0; y < tam; y++){
            	printf("%d", matriz[x][y]);
        	}
        	printf("\n");
    	}
    	printf("\n");
    }
	return 0;
}


/* 10698 UVA */
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

struct equipo {
	int puntaje,partidos,nuevoPuntaje, perdidas;
	string nombreEquipo;
	bool operator<(const equipo& a) const{
		if (puntaje != a.puntaje){
			return puntaje > a.puntaje;
		}
		if (nuevoPuntaje - perdidas != a.nuevoPuntaje - a.perdidas){
			return nuevoPuntaje - perdidas > a.nuevoPuntaje - a.perdidas;
		}
		if (nuevoPuntaje != a.nuevoPuntaje){
			return nuevoPuntaje > a.nuevoPuntaje;
		}
		string u = nombreEquipo;
		string j = a.nombreEquipo;
		transform(nombreEquipo.begin(), nombreEquipo.end(), u.begin(), ::tolower);
		transform(a.nombreEquipo.begin(), a.nombreEquipo.end(), j.begin(), ::tolower);
		return u < j;
	}

	bool operator==(const equipo& a) const {
		if (puntaje == a.puntaje && nuevoPuntaje - perdidas == a.nuevoPuntaje - a.perdidas && nuevoPuntaje == a.nuevoPuntaje){
			return true;
		}
		return false;
	}
};

int main() {
	
	int totalEquipos, equipo1, equipo2, partidos;
	int gol1, gol2, ganador, perdedor, tablaPos;
	string s,s1;
	bool lider = true;
	equipo aux, prev, equipos[28];
	char basura;
	
	cin >> totalEquipos >> 	partidos;
	
	while (totalEquipos != 0) {
		if (!lider){
			printf("\n");
		}
		lider = false;
		for (int i = 0; i < totalEquipos; i++) {
			cin >> s; 
			equipos[i].nombreEquipo = s;
			equipos[i].partidos = 0;
			equipos[i].puntaje = 0;
			equipos[i].nuevoPuntaje = 0;
			equipos[i].perdidas = 0;
		}
		for (int i = 0; i < partidos; i++) {
			cin >> s >> gol1 >> basura >> gol2 >> s1;
			for (int i = 0; i < totalEquipos; i++) {
				if (equipos[i].nombreEquipo == s){
					equipo1 = i;
				}else if(equipos[i].nombreEquipo == s1){
					equipo2 = i;
				}
			}
			if(gol1 > gol2){
				ganador = 3, perdedor = 0;
			}else if(gol1 == gol2){
				ganador = perdedor = 1;
			}else{ 
				ganador = 0, perdedor = 3;
			}
			
			aux = equipos[equipo1];
			aux.puntaje += ganador; 
			aux.partidos++; 
			aux.nuevoPuntaje += gol1; 
			aux.perdidas += gol2;			
			equipos[equipo1] = aux;
			aux = equipos[equipo2];
			aux.puntaje += perdedor; 
			aux.partidos++; 
			aux.nuevoPuntaje += gol2; 
			aux.perdidas += gol1;			
			equipos[equipo2] = aux;
		}
		sort(equipos, equipos + totalEquipos);
		tablaPos = 1;
		for (int i = 0; i < totalEquipos;i++) {
			aux = equipos[i];
			if (i>0 && aux == prev){
				printf("%4c",' ');
			}else{
				printf("%2d. ",tablaPos);
			}

			printf("%15s%4d%4d%4d%4d%4d", aux.nombreEquipo.c_str(), aux.puntaje, aux.partidos, aux.nuevoPuntaje, aux.perdidas, aux.nuevoPuntaje - aux.perdidas);
			
			double res = 100*aux.puntaje/(3*aux.partidos);
			
			if (aux.partidos==0){
				printf("%7s\n","N/A");
			}else{
				printf("%7.2lf\n",res);
			}
			
			tablaPos++;
			prev = aux;
		}
		cin >> totalEquipos >> partidos;
	}
}

/* 574 UVA */

/* Con Backtracking */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
int arr1[50], arr2[50], numerosPosibles;
 
int busqueda(int val, int pos, int len) {
    int enc = 0;
    if (pos >= numerosPosibles || val < 0){
    	return 0;
    }
    val -= arr1[pos]; 
    arr2[len++] = arr1[pos++];
    if (val == 0){
        for (int i = 0; i < len; i++){
            printf("%d", arr2[i]);
            if(i != len - 1){
            	printf("+");
            }else{
            	printf("\n");
            }
        }
        return 1;
    }
    for (int i = pos; i < numerosPosibles; i++){
        if ((i - pos) == 0 || arr1[i] != arr1[i - 1]){
            enc += busqueda(val, i, len);
        }
    }
    return enc;
}
 
int main() {
    int valores;
    while (scanf("%d %d", &valores, &numerosPosibles) && valores && numerosPosibles) {
        int i, res = 0;
        for (i = 0; i < numerosPosibles; i++){
        	scanf("%d", &arr1[i]);
        }
        sort(arr1, arr1 + numerosPosibles);
        reverse(arr1, arr1 + numerosPosibles);
        printf("Sums of %d:\n", valores);
        for (i = 0; i < numerosPosibles; i++){
            if (i == 0 || arr1[i] != arr1[i - 1]){
                res += busqueda(valores, i, 0);
            }
        }
        if (res == 0){
        	printf("NONE\n");
        }
    }
    return 0;
}


/* Sin Backtracking*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;


vector<int> convertir(int num, int tam){
	vector<int> arr(tam);
	for (x = 0; x < tam; x++) { 
		arr[x] = num % 2; 
		num = num / 2; 
		if(num == 0){
			return arr; 
		}
	}
}

int main(){
	int arr1[50];
	int numero, tamPos, i;
	vector<vector<int>> posible;

	while(scanf("%d %d", &numero, &tamPos) && numero && tamPos){
		for (i = 0; i < tamPos; i++){
        	scanf("%d", &arr1[i]);
        }

        for(i = 0; i < tamPos; i++){
        	vector<int> arr3 = convertir(i,tamPos);
        	int suma, cont1 = 0, cont2 = 0;
        	for(j = 0; j < tamPos; j++){
        		if(arr3[j] == 1){
        			suma += arr3[j];
        			posible[cont1][cont2] = arr1[j];
        			cont2++;
        		}
        	}
        	if(suma == numero){

        	}
        }
	}
	return 0;
}


/* Taller 9 Estructuras de Datos */

/* 13055 UVA */


/*
La complejidad de este algoritmo es de O(n) ya que solo tiene un while que itera las mismas veces que los casos de UVA. 
Es aceptado porque UVA acepta hasta una complejidad de 10^9.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  stack<string> dreams;
  string nombres;
  string orden;
  int a;
  cin >> a;
  while(a--){
    cin >> orden;
    if(orden == "Sleep"){
      cin >> nombres;
      dreams.push(nombres);
    }
    else if(orden == "Kick"){
      if(dreams.empty() == false){
        dreams.pop();
      }
    }
    else{
      if(dreams.empty() == true){
        cout << "Not in a dream" << endl;
      }
      else{
        cout << dreams.top() << endl;
      }
    }
  }
}

/* 127 UVA */


/*
La complejidad de este algoritmo es de O(n+n) ya que solo tiene un while que itera las mismas veces que los casos de UVA. 
Es aceptado porque UVA acepta hasta una complejidad de 10^9.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
 
int main() {
 
	string in;
	while (cin >> in) {
	    if(in[0] == '#'){
	        break;
	    }
		vector< stack< string > > mazo;
		stack<string> pilaCantCar;
		
		pilaCantCar.push(in);
		mazo.push_back(pilaCantCar);
		
		for (int i = 1; i < 52; i++){
			stack<string> pilaCantCar;
			
			cin >> in;
			
			pilaCantCar.push(in);
			mazo.push_back(pilaCantCar);
		}
 
		for (int i = 1; i < mazo.size(); i++) {
			if (i >= 3 && (mazo[i].top()[0] == mazo[i - 3].top()[0] || mazo[i].top()[1] == mazo[i - 3].top()[1])) {
				mazo[i - 3].push(mazo[i].top());
				mazo[i].pop();
				if (mazo[i].empty()){
					mazo.erase(mazo.begin() + i, mazo.begin() + i + 1);
				}
				i = i - 4;
			}else if (i >= 1 && (mazo[i].top()[0] == mazo[i - 1].top()[0] || mazo[i].top()[1] == mazo[i - 1].top()[1])){
				mazo[i - 1].push(mazo[i].top());
				mazo[i].pop();
				if (mazo[i].empty()){
					mazo.erase(mazo.begin() + i, mazo.begin() + i + 1);
				}
				i = i - 2;
			}
 
		}
 
		int tamMazo = mazo.size();

		if(tamMazo == 1){
			cout << tamMazo << " pile remaining:";
		}else{
			cout << tamMazo << " piles remaining:";
		}
		for (int i = 0; i < tamMazo; i++){
			cout << " " << mazo[i].size();
		}
		cout << endl;
	}
	return 0;
}


/* 642 UVA */


/*
La complejidad de este algoritmo es de O(n^2) ya que solo tiene un while que itera las mismas veces que los casos de UVA. 
Es aceptado porque UVA acepta hasta una complejidad de 10^9.
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
  string words;
  cin >> words;
  list<string> dicc;
  list<string> prints;
  while(words != "XXXXXX"){
    dicc.push_back(words);
    cin >> words;
  }
  dicc.sort();
  string wordscramble;
  cin >> wordscramble;
  while(wordscramble != "XXXXXX"){
    for(list<string>::iterator j = dicc.begin(); j != dicc.end(); j++){
      bool flag = false;
      if(wordscramble.size() == (*j).size()){
        int contador = 0;
        for(int i = 0; i < wordscramble.size(); i++){
          for(int k = 0; k < (*j).size(); k++){
            if(wordscramble[i] == (*j)[k]){
              contador++;
            }
          }
          if(contador == (*j).size()){
            string temp = (*j);
            prints.push_back(temp);
            flag = true;
          }
        }
      }
      /*

      Esto genera problemas al implementarse, en el momento de la impresion

      if(flag == false){
        prints.push_back("NOT A VALID WORD");
        break;
      }
      */
    }
    for(list<string>::iterator it = prints.begin(); it != prints.end(); it++){
      cout << *it << endl;
    }
    cout << "******" << endl;
    prints.clear();
    cin >> wordscramble;
  }

  return 0;
}

/* 492 UVA */


/*
La complejidad de este algoritmo es de O(n+n) ya que solo tiene un while que itera las mismas veces que los casos de UVA. 
Es aceptado porque UVA acepta hasta una complejidad de 10^9.
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(){
    string word; 
    getline(cin, word);
    string changeWord; 
    string changedWord = "";
    list<string> wordC;
    while(word != "\0"){
	    int length = 0, index = 0;
	    while(word[index] != '\0'){
	        if(word.find(' ', index) != -1){
	            length = word.find(' ', index);
	            length -= index;
	            changeWord = word.substr(index, length);
	            changeWord.insert(length, "ay");
	            changeWord.insert(length, 1, word[index]);
	            changeWord.erase(0, 1);
	            index += length + 1;
	        }
	        else{
	            changeWord = word.substr(index);
	            length = changeWord.length();
	            changeWord.insert(length, "ay");
	            changeWord.insert(length, 1, word[index]);
	            changeWord.erase(0, 1);
	            index = word.length();
	        }
	        changedWord += (changeWord + " ");
	    }
	    wordC.push_back(changedWord);
	    cout << wordC.front() << endl;
	    getline(cin, word);
    }
    return 0;
}

/* 551 UVA */


/*
La complejidad de este algoritmo es de O(n) ya que solo tiene un while que itera las mismas veces que los casos de UVA. 
Es aceptado porque UVA acepta hasta una complejidad de 10^9.
*/

#include <cstdio>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
	stack<char> pila;
	string estoEsUnaFrase;
	while (cin >> estoEsUnaFrase){
		int temp = 0;
		int lenFrase = estoEsUnaFrase.length(); 
		int i;
		for (i = 0; i < lenFrase; i++) {
			temp++;
			if (estoEsUnaFrase[i] == '(' || estoEsUnaFrase[i] == '[' || estoEsUnaFrase[i] == '<' || estoEsUnaFrase[i] == '{') {
				if (estoEsUnaFrase[i] == '(' && estoEsUnaFrase[i + 1] == '*') {
					pila.push('*');
					i++;
				} else {
					pila.push(estoEsUnaFrase[i]);
				}
			} else if ((estoEsUnaFrase[i] == ')' || estoEsUnaFrase[i] == ']' || estoEsUnaFrase[i] == '>' || estoEsUnaFrase[i] == '}') || (estoEsUnaFrase[i] == '*' && estoEsUnaFrase[i + 1] == ')')) {
				if (pila.empty())
					break;
				if (estoEsUnaFrase[i] == '*') {
					if (pila.top() != '*') {
						break;
					}
					pila.pop();
					i++;
				} else if (estoEsUnaFrase[i] == ')') {
					if (pila.top() != '(') {
						break;
					}
					pila.pop();
				} else if (estoEsUnaFrase[i] == ']') {
					if (pila.top() != '[') {
						break;
					}
					pila.pop();
				} else if (estoEsUnaFrase[i] == '>') {
					if (pila.top() != '<') {
						break;
					}
					pila.pop();
				} else if (estoEsUnaFrase[i] == '}') {
					if (pila.top() != '{') {
						break;
					}
					pila.pop();
				}
			}
		}

		if (i < lenFrase || !pila.empty()) {
			if (i >= lenFrase && !pila.empty()){
				temp++;
			}
			printf("NO %d\n", temp);
		} else{
			printf("YES\n");
		}

		while (!pila.empty())
			pila.pop();
	}

	return 0;
}


/* Taller 10 Estructuras de Datos */


/* 10226 UVA */
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	int casos;
	string s;

	cin >> casos;
	getline(cin, s);
	getline(cin, s);

	while(casos--){
		int temp = 0;
		map<string, int> res;
		while(getline(cin, s) && s != ""){
			res[s]++;
			temp++;
		}
		
		for (map<string, int>::iterator i = res.begin(); i != res.end(); i++){
			printf("%s %.4f\n", (*i).first.data(), (*i).second*100./temp);
		}

		if(casos > 0){
			cout << endl;
		}
	}
}

/* 10901 UVA */
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int casos;
    int carros, tardaTransito, movimientos;
    int tiempo;
    string lado;
    int tll[10004];
    int ts[10004];
    queue<int> ferry[2];
    
    cin >> casos;
    while (casos--){
        cin >> carros >> tardaTransito >> movimientos;
        for (int i = 0; i < movimientos; i++){
            cin >> tiempo >> lado;
            tll[i] = tiempo;
            if (lado == "left"){
            	ferry[0].push(i);
            }else{
            	ferry[1].push(i);
            }
        }
        int tiempoP = 0;
        int ladoP = 0;
        while (!ferry[0].empty() || !ferry[1].empty()){
            int sigF;
            if(ferry[0].empty()){
            	sigF = tll[ferry[1].front()];
            }else if(ferry[1].empty()){
            	sigF = tll[ferry[0].front()];
            }else{
            	sigF = min(tll[ferry[0].front()], tll[ferry[1].front()]);
            }
            
            tiempoP = max( tiempoP, sigF );
            int cnt = 0;
            
            while (!ferry[ladoP].empty() && tll[ferry[ladoP].front()] <= tiempoP && cnt < carros){
                ts[ferry[ladoP].front()] = tiempoP + tardaTransito;
                cnt++;
                ferry[ladoP].pop();
            }
            tiempoP += tardaTransito;
            ladoP = (ladoP + 1) % 2;
        }
        for (int i = 0; i < movimientos; i++){
        	cout << ts[i] << endl;
        }
        if (casos > 0){
        	cout << endl;
        }
    }
    return 0;
}


/* 642 UVA */
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	string indice, palabra;
	map<string,string> dicc;
	while(cin >> palabra && palabra != "XXXXXX"){
		indice = palabra;
		sort(indice.begin(),indice.end());
		dicc[palabra] = indice;
	}
	while(cin >> palabra && palabra != "XXXXXX"){
		bool flag = false;
		sort(palabra.begin(),palabra.end());
		for(map<string, string>::iterator it = dicc.begin(); it != dicc.end(); it++){
			if(it->second == palabra){
				cout<< it->first <<endl;
				flag=true;
			}
		}
		if(!flag){
			cout<<"NOT A VALID WORD"<<endl;
		}
		cout<<"******"<<endl;
	}
    return 0;
}

/* 12100 UVA */
#include <queue>
#include <iostream>
using namespace std;
int main(){
    int cases, n, m; 
    cin >> cases;
    while(cases--){
        int x, firstNum, numPos;
        cin >> n >> m;
        queue<int> prints; 
        queue<int> pos;
        int numQueue[10] = {};
        for(int i = 0; i < n; i++){
            cin >> x;
            prints.push(x); 
            pos.push(i);
            numQueue[x]++;
        }
        int count = 0;
        while(true){
            firstNum = prints.front(); 
            prints.pop();
            numPos = pos.front();
            pos.pop();
            int elimNum = 1;
            for(int i = firstNum + 1; i < 10; i++){
                elimNum = elimNum & numQueue[i] == 0;
            }
            if(elimNum != 0){
                count++;
                if(numPos == m){
                    cout << count << endl;;
                    break;
                }
                numQueue[firstNum]--;
            } 
            else{
                prints.push(firstNum);
                pos.push(numPos);
            }
        }
    }
    return 0;
}



/* Tarea 1 Arboles y Grafos */


/* 11629 UVA */
#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

int main(){
	int cantParty, guess;
	while(scanf("%d%d", &cantParty, &guess)){
		map<string, double> db;
		for (int i = 1; i <= cantParty; i++){
			string party;
			double valParty;
			cin >> party >> valParty;
			db[party] = valParty;
		}
		for (int i = 1; i <= guess; i++){
			string party;
			double temp = 0;
			double valParty;
			cin >> party;
			temp += db[party];
			cin >> party;
			while(party == "+"){
				cin >> party;
				temp += db[party];
				cin >> party;
			}
			cin >> valParty;
			int resultado = 0;
			if(party == "<"){
				resultado = (temp + 0.001 < valParty);
			}else if(party == ">"){
				resultado = (temp - 0.001 > valParty);
			}else if(party == "<="){
				resultado = (temp - 0.001 <= valParty);
			}else if(party == ">="){
				resultado = (temp + 0.001 >= valParty);
			}else if(party == "="){
				resultado = (fabs(temp - valParty) < 0.01);
			}
			printf("Guess #%d was %s\n", i, resultado ? "correct." : "incorrect.");
		}
	}
	return 0;
}

import math

def main():
    x = input()
    partido = int(x.split(" ")[0])
    predicciones = int(x.split(" ")[1])
    dic = {}
    
    for i in range(partido):
    	y = input()
    	dic[y.split(" ")[0]] = float(y.split(" ")[1])
    for i in range(predicciones):
    	y = input()
    	z = y.split(" ")
    	contador = 0.0
    	comp = 0
    	resultado = False
    	correcto = False
    	for j in z:
    		if j in dic:
    			contador += dic[j]
    		elif j == "<":
    			comp = 1
    			resultado = True
    		elif j == "=":
    			comp = 2
    			resultado = True
    		elif j == ">":
    			comp = 3
    			resultado = True
    		elif j == "<=":
    			comp = 4
    			resultado = True
    		elif j == ">=":
    			comp = 5
    			resultado = True
    		elif resultado:
    			if comp == 1:
    				correcto = (contador + 0.001 < float(j))
    			elif comp == 2:
    				correcto = (abs(contador - float(j)) < 0.01)
    			elif comp == 3:
    				correcto = (contador - 0.001 > float(j))
    			elif comp == 4:
    				correcto = (contador - 0.001 <= float(j))
    			elif comp == 5:
    				correcto = (contador + 0.001 >= float(j))
    	
    	if correcto:
    		print("Guess #%d was correct." %(i + 1))
    	else:
    		print("Guess #%d was incorrect." %(i + 1))
		
if __name__ == '__main__':
    main()


/* 1203 UVA */
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Argus{
	int num, per, count;
}arg, temp;

bool operator < (const Argus &x, const Argus &y){
	if(x.per == y.per){
		return x.num > y.num;
	}else{
		return x.per > y.per;
	}
}

int main(){
	int k, i, queries;
	char str[100];
	priority_queue<Argus> ar;
	
	while(scanf("%s", str) && str[0] != '#'){
		scanf("%d%d", &arg.num, &arg.per);
		arg.count = arg.per;
		ar.push(arg);
	}
	
	scanf("%d", &queries);
	
	while(queries--){
		temp = ar.top();
		ar.pop();
		printf("%d\n", temp.num);
		temp.per += temp.count;
		ar.push(temp);
	}
	return 0;
}


/* 11988 UVA */
#include <iostream>
#include <string>

using namespace std;

int main(){
	char str[100005];
	
	while(scanf("%s", str + 1) != EOF){
		int temp[1000005] = {0};
		int act = 0, ult = 0;
		
		for(int i = 1; str[i]; ++i){
			if(str[i] == '['){
				act = 0;
			}else if(str[i] == ']'){
				act = ult;
			}else{
				temp[i] = temp[act];
				temp[act] = i;
				if(act == ult){
					ult = i;
				}
				act = i;
			}
		}

		for(int i = temp[0]; i != 0; i = temp[i]){
			if(str[i] != '[' && str[i] != ']'){
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

import sys

stream = sys.stdin

def readline():
	return stream.readline().strip()

def main():
	n = [0] * (100000 + 5)

	while True:
		line = readline()
		if not line:
			break

		head = cur = last = 0
		n[head] = 0

		line = ' ' + line

		for i in range(1, len(line)):
			if line[i] == '[':
				cur = head
			elif line[i] == ']':
				cur = last
			else:
				n[i] = n[cur]
				n[cur] = i
				if last == cur:
					last = i
				cur = i

		i = 0
		while n[i] != 0:
			sys.stdout.write(line[n[i]])
			i = n[i]

		print()

if __name__ == '__main__':
	main()


/* 10172 UVA */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n, s, q, a = 0, count = 0;
		vector<queue<int>> v;
		stack<int> st;
		cin >> n >> s >> q;

		for(int i = 0; i < n; i++){
			int temp1;
			queue<int> k;
			cin >> temp1;
			for(int i = 0; i < temp1; i++){
				int temp2;
				cin >> temp2;
				k.push(temp2);
			}
			v.push_back(k);
		}

		while(true){
			while(!st.empty()){
				if(st.top() != a + 1){
					if(v[a].size() < q){
						v[a].push(st.top());					
					}else{
						break;
					}
				}
				st.pop();
				count++;
			}
			while(!v[a].empty() && st.size() < s){
				st.push(v[a].front());
				v[a].pop();
				count++;
			}
			int flag = 1;
			for(int i = 0; i < v.size(); i++){
				if(v[i].size() > 0){
					flag = 0;
					break;
				}
			}
			if(flag && st.empty()){
				break;
			}
			a++;
			a %= n;
			count += 2;
		}
		cout << count << endl;
	}
	return 0;
}


/* 11111 UVA */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(){
	string entrada,temp;
	vector<int> matrioshka;    
    while(getline(cin,entrada)){
        if(entrada[0] == '\0'){
            continue;
        }

        matrioshka.clear();
        stringstream ss(entrada);
        stack<int> muñecas, numMuñecas;

        while(ss >> temp){
            matrioshka.push_back(stoi(temp));
        }

        if(matrioshka.size() % 2){
            cout<<":-( Try again."<<endl;
            continue;
        }

        int flag = 0;

        for(int i = 0; i < matrioshka.size(); i++){

            if(matrioshka[i] < 0){
                if(!numMuñecas.empty()){
                    if(muñecas.top() <= abs(matrioshka[i])){
                        flag = 1;
                        break;
                    }
                    int res = muñecas.top() - abs(matrioshka[i]);
                    muñecas.pop();
                    muñecas.push(res);
                }
                muñecas.push(abs(matrioshka[i]));
                numMuñecas.push(matrioshka[i]);
            }
            else{
                if(numMuñecas.empty() || -numMuñecas.top() != matrioshka[i]){
                    flag = 1;
                    break;
                }
                muñecas.pop();
                numMuñecas.pop();
            }

        }
        if(flag == 1){
            cout<<":-( Try again."<<endl;
        }else{
            cout<<":-) Matrioshka!"<<endl;
        }
    }
    return 0;
}

/* 790 UVA */
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

struct data{
	int id, time;
	char pn, verdict;
	
	data(int a, char b, int c, char d){
		id = a, pn = b, time = c, verdict = d;
	}

	bool operator < (const data &p){
		if( time == p.time){
			return verdict < p.verdict;
		}else{
			return time < p.time;
		}
	}
};


struct node{
	int id, wr[10], solve[10], time, ac;

	bool operator < (const node &p){
		if(p.ac == ac){
			if(p.time == time){
				return id < p.id;
			}else{
				return time < p.time;
			}
		}else{
			return ac > p.ac;
		}
	}
};

int main(){
	vector<data> vec;
	node v[26];
	char s[50];
	int t, id, pen, h, m, max1;
	char verdict, c, pn;

	cin >> t;
	getchar();
	getchar();

	while(t--){
		for(int i = 0; i < 26; i++){
			memset(v[i].wr, 0, sizeof(v[i].wr));
			memset(v[i].solve, 0, sizeof(v[i].solve));
			v[i].id = 0;
			v[i].time = 0;
			v[i].ac = 0;
		}
		vec.clear();

		while(gets(s)){
		    if(s[0] == '\0'){
		        break;
		    }
		    sscanf(s, "%d %c %d %c %d %c", &id, &pn, &h, &c, &m, &verdict);
			int time = h * 60 + m;
			vec.push_back(data(id, pn, time, verdict));
		}

		sort(vec.begin(), vec.end());
		int length = vec.size();
		max1 = 0;

		for(int i = 0; i < length; i++){
			data temp = vec[i];
			if(temp.id > max1){
				max1 = temp.id;
			}
			v[temp.id].id = temp.id;
			if(temp.verdict == 'Y' && !v[temp.id].solve[temp.pn - 64]){
				v[temp.id].solve[temp.pn - 64] = 1;
				v[temp.id].time += v[temp.id].wr[temp.pn - 64] * 20 + temp.time;
				v[temp.id].ac++;
			}
			if(temp.verdict == 'N' && v[temp.id].solve[temp.pn - 64]){
				v[temp.id].wr[temp.pn - 64]++;
			}
		}
		for(int i = 1; 1 <= max1; i++){
			v[i].id = i;
			sort(v+1, v+26);
			printf("RANK TEAM PRO/SOLVED TIME\n");
			int k = 1;
			for(int i = 0; i < 26; i++){
				if(v[i].id){
					int accpt = v[i].ac, tim = v[i].time;
					int cnt = 0;
					while(v[i].ac == accpt && v[i].time == tim && v[i].id){
						printf("%4d %4d", k, v[i].id);
						if(v[i].ac){
							printf(" %4d", v[i].ac);
						}
						if(v[i].time){
							printf("%10d", v[i].time);
						}
						cout << endl;
						cnt++;
						i++;
					}
					i--;
					k += cnt;
				}
			}
		}
		if(t){
			cout << endl;
		}
	}
}


/* Taller 3 Arboles y Grafos */

/* 10706 UVA */

/*
#include <iostream>

typedef long long int ll;

using namespace std;

ll inp(int n){
	ll res = n * (n + 1) / 2;
	ll pow = 10;
	while (pow <= n){
		res += (n - pow + 1) * (n - pow + 2) / 2;
		pow *= 10;
	}
	return res;
}

int main(){
	int tc;
	cin >> tc;
	
	while(tc--){
		ll s = 1, e = 1e9;
		ll res = 1;
		ll target;
		cin >> target;
		while(s <= e){
			int mid = (s + e) / 2;
			if(inp(mid) == target){
				res = mid;
				break;
			}else if(inp(mid) > target){
				res = mid;
				e = mid - 1;
			}else{
				s = mid + 1;
			}
		}
		int index = target - inp(res - 1);
		string any = "";
		for(int i = 1; i <= res; i++){
			any += to_string(i);
		}
		cout << any[index - 1] << endl;
	}
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> digitos(35000);

void generarSecuencia(){
	long long sa = 0;
	long long ss = 1;

	for (int i = 1; i < 35000; ++i)
	{
		sa = sa + ss;
		ss = ss + floor(log10(i + 1)) + 1;
		digitos[i] = sa;
	}
}


int main(){
	int casos;

	cin >> casos;
	generarSecuencia();
	while(casos--){
		long long obj;
		cin >> obj;
		int low = 0, high = 35001, res;
    //cout << "xD 1" << endl;
		while((low + 1) != high){
      //cout << "entro" << endl;
			int mid = (low + high) / 2;
			if(digitos[mid] == obj){
				res = mid;
        //cout << "xD 2" << endl;
				break;
			}else if(digitos[mid] > obj){
        //cout << "xD 3" << endl;
				res = mid;
				high = mid;
			}else{
				low = mid;
        //cout << "xD 4" << endl;
			}
      //cout << "Este es el high: "<< high << endl;
      //cout <<  "Este es el low: " << low << endl;
      //cout <<  "Este es el mid: " << mid << endl;
		}
    //res = high;
    //cout << res << endl;
		string sec = "";
    //cout << "xD 5" << endl;
		for (int i = 1; i <= res; ++i){
			sec += to_string(i);
      //cout << "xD 7" << endl;
		}
		int indice = obj - (digitos[res] - sec.size());
    //cout << indice << endl;
		cout << sec[indice - 1] << endl;
    //cout << "xD 6" << endl;
	}
	return 0;
}

/* 11518 UVA */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[100000];
int n, m, k;
int color[100000];

void dfs(int u){
	color[u] = 2;
	for(int k = 0; k < v[u].size(); k++){
		int x = v[u][k];
		if(color[x] == 0){
			dfs(x);
		}
	}
	color[u] = 1;
}

int main(){
	int t, x, y;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> m >> k;
		for(int j = 1; j <= m; j++){
			cin >> x >> y;
			v[x].push_back(y);
		}
		int lol;
		while(k > 0){
			cin >> lol;
			dfs(lol);
			k--;
		}
		int co = 0;
		for(int p = 1; p <= n; p++){
			if(color[p] == 0){
				co++;
			}
		}
		cout << n - co << endl;

		for(int p = 1; p <= n; p++){
			v[p].clear();
			color[p] = 0;
		}
	}
	return 0;
}

def dfs(grafo, visitado, vertice):
	visitado[vertice] = 1
	for n in grafo[vertice]:
		if not visitado[n]:
			dfs(grafo, visitado, n)

t = int(input())

for i in range(t):
	n, m, l = map(int, input().split())
	
	grafo = [[] for i in range(n)]
	visitado = [0 for i in range(n)]

	for i in range(m):
		u, v = map(int, input().split())
		grafo[u - 1].append(v - 1)

	for i in range(l):
		v = int(input())
		dfs(grafo, visitado, v - 1)

	print(sum(visitado))


/* 10668 UVA */

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double n, C, L;
	
	cin >> L >> n >> C;
	while(L >= 0 && n >= 0 && C >= 0){
		double ele = (1.0 + n * C);
		double low = 0.0, high = acos(-1.0) / 2;
		double radio, altura;
		while(high - low > 1e-12){
			double mid = (low + high) / 2.0;
			if(ele * sin(mid) - mid > 0){
				low = mid;
			}else{
				high = mid;
			}
		}

		radio = L / 2.0 / sin(low);
		altura = radio * cos(low);

		if(radio - altura < 1e-12 || low < 1e-12){
			printf("0.000\n");
		}else{
			printf("%.3lf\n", radio - altura);
		}
		cin >> L >> n >> C;
	}
	return 0;
}

/* 11686 UVA */

#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

vector<int> topoSortKahn(vector<vector<int>> &grafo, vector<int> &vertices){
	vector<int> lista;
	queue<int> cola;

	for(int i = 1; i < vertices.size(); i++){
		if(!vertices[i]){
			cola.push(i);
		}
	}

	while(!cola.empty()){
		int temp = cola.front();
		cola.pop();
		lista.push_back(temp);
		for (int i = 0; i < grafo[temp].size(); i++){
			int temp2 = grafo[temp][i];
			vertices[temp2]--;
			if(vertices[temp2] == 0){
				cola.push(temp2);
			}
		}
	}
	return lista;
}

int main(){
	int n, m;
	cin >> n >> m;
	while(n != 0 && m != 0){
		vector<vector<int>> grafo(n + 1);
		vector<int> vertices(n + 1, 0);
		for (int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			vertices[b]++;
			grafo[a].push_back(b);
		}

		vector<int> tsk = topoSortKahn(grafo, vertices);

		if(tsk.size() == grafo.size() - 1){
			for (int i = 0; i < tsk.size(); i++){
				printf("%d\n", tsk[i]);				
			}
		}else{
			printf("IMPOSSIBLE\n");
		}

		cin >> n >> m;
	}
	return 0;
}

/* 10610 UVA */

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <queue>
#include <math.h>

using namespace std;

void bfs(vector<pair<double, double>>& entradas, int velocidad, int minutos) {
	bool esPosible, completado;
	int hoyosVisitados, hoyoActual;
	double distancia, x, y, tiempo;
	vector<int> visitados, visTemp;
	queue<int> hoyos;

	for(int i = 0; i < entradas.size(); ++i){
		visitados.push_back(0);
	}
	visTemp = visitados;

	esPosible = false;
	hoyosVisitados = 0;
	hoyos.push(0);
	visitados[0] = 1;
	while(!hoyos.empty()) {
		hoyoActual = hoyos.front();
		hoyos.pop();
		for(int i = 0; i < entradas.size(); ++i){
			if(i != hoyoActual && !visitados[i]){
				x = entradas[i].first - entradas[hoyoActual].first;
				y = entradas[i].second - entradas[hoyoActual].second;
				distancia = sqrt(pow(x, 2) + pow(y, 2));
				tiempo = distancia / velocidad;
				tiempo /= 60;
				if(tiempo < minutos){
					if(i == 1){
						esPosible = true;
						while(!hoyos.empty()){
							hoyos.pop();
						}
						visTemp[i] = hoyoActual;
						break;
					}
					hoyos.push(i);
					visitados[i] = 1;
				}
				visTemp[i] = hoyoActual;
			}
		}
	}

	hoyoActual = visTemp[1];
	completado = false;
	int j = 0;
	while(!completado){
		if(j == hoyoActual){
			if(!hoyoActual){
				completado = true;
			}else{
				hoyosVisitados++;
			}
			hoyoActual = visTemp[hoyoActual];
		}

		j++;
		if(j == entradas.size()){
			j = 0;
		}
	}

	if(esPosible){
		cout << "Yes, visiting " << hoyosVisitados << " other holes." << endl;
	}else{
		cout << "No." << endl;
	}
}

int main() {
	bool ver;
	string entrada, numero;	
	int velocidad, minutos;
	double xs, ys;
	pair<double, double> llenar;
	vector<pair<double, double>> entradas;

	cin >> velocidad >> minutos;
	cin.ignore();
	while(velocidad || minutos) {
		getline(cin, entrada);
		while(entrada.size()) {
			numero = "";
			ver = false;
			entrada += '\n';
			for(int i = 0; i < entrada.size(); ++i) {
				if(entrada[i] != ' ' && entrada[i] != '\n'){
					numero += entrada[i];
				}else if((entrada[i] == ' ' || entrada[i] == '\n') && numero.size() > 0){
					if(!ver){
						ver = true;
						xs = stod(numero);
					}else{
						ys = stod(numero);
					}
					numero = "";
				}
			}
			llenar.first = xs;
			llenar.second = ys;
			entradas.push_back(llenar);
			getline(cin, entrada);
		}

		bfs(entradas, velocidad, minutos);
		entradas.clear();

		cin >> velocidad >> minutos;
		cin.ignore();
	}

	return 0;
}

/* 10044 UVA */

#include <bits/stdc++.h>

using namespace std;

int main(){
	int scenario, papers, nombres, count, countsc = 1;
	string s, temp, p;
	vector<string> v;
	map<string, vector<string>> mp;
	map<string, int> visitados, nivel;
	queue<string> q;

	cin >> scenario;

	while(scenario--){
		temp = "";
		scanf("%d %d\n", &papers, &nombres);
		getchar;
		while(papers--){
			getline(cin, s);
			count = 0;
			for(string::iterator it = s.begin(); it != s.end(); it++){
				if(*it == ','){
					count++;
				}else if(*it == ':'){
					v.push_back(temp);
					temp = p;
					count = 0;
					break;
				}
				if(count == 2){
					v.push_back(temp);
					temp = p;
					count = 0;
				}else if(*it == ' ' && temp == ""){
					continue;
				}else{
					temp += *it;
				}
			}
			count = v.size();
			for (int i = 0; i < count; i++){
				for (int j = i + 1; j < count; j++){
					mp[v[i]].push_back(v[j]);
					mp[v[j]].push_back(v[i]);
				}
			}
			v.clear();
		}
		q.push("Erdos, P.");
		nivel["Erdos, P."] = 0;
		visitados["Erdos, P."] = 1;
		while(!q.empty()){
			temp = q.front();
			q.pop();
			for(vector<string>::iterator it = mp[temp].begin(); it != mp[temp].end(); it++){
				if(visitados[*it] == 0){
					visitados[*it] = 1;
					nivel[*it] = nivel[temp] + 1;
					q.push(*it);
				}
			}
		}
		cout << "Scenario " << countsc++ << endl;
		while(nombres--){
			getline(cin, s);
			if(visitados[s] == 0){
				cout << s << " infinity\n";
			}else{
				cout << s << " " << nivel[s] << endl;
			}
		}
		mp.clear();
		visitados.clear();
		nivel.clear();
		while(!q.empty()){
			q.pop();
		}
	}
	return 0;
}


/* 11060 UVA */

#include <bits/stdc++.h>

using namespace std;

vector<int> topoSort(vector<vector<int>> g, vector<int> visitados){
	int n = g.size();
	vector<int> order;
	priority_queue<int> q;

	for(int i = 0; i < n; i++){
		if(!visitados[i]){
			q.push(-i);
		}
	}

	while(!q.empty()){
		int u = -q.top();
		q.pop();
		order.push_back(u);
		for(int v = 0; v < g[u].size(); v++){
			int temp3 = g[u][v];
			visitados[temp3]--;
			if(!visitados[temp3]){
				q.push(-temp3);
			}
		}
	}
	return order;
}

int main(){
	int n;
	int count = 0;
	while(cin >> n){
		
		vector<string> bebida(n);
		vector<int> visitados(n, 0);
		map<string, int> maf;
		for(int i = 0; i < n; i++){
			string beb;
			cin >> beb;
			bebida[i] = beb;
			maf[beb] = i;
		}

		vector<vector<int>> g(n);
		int m;
		cin >> m;

		for(int i = 0; i < m; i++){
			string u, v;
			cin >> u >> v;
			int temp = maf[u];
			int temp2 = maf[v];
			g[temp].push_back(temp2);
			visitados[temp2]++;
		}

		vector<int> order = topoSort(g, visitados);

		cout << "Case #" << ++count << ": Dilbert should drink beverages in this order:";
		for(int i = 0; i < n; i++){
			cout << " " << bebida[order[i]];
		}
		cout << ".\n";
		cout << "\n";
	}
	return 0;
}


/* 852 UVA */

#include <bits/stdc++.h>

using namespace std;

int moveX[] = {1, -1, 0, 0};
int moveY[] = {0, 0, -1, 1};
bool visitados[10][10];
char tablero[10][10];
bool blancoN, negroN;
int puntos, blanco, negro;

bool entradaValida(int x, int y){
	return x >= 0 && y >= 0 && x < 9 && y < 9;
}

void dfs(int x, int y){
	visitados[x][y] = 1;
	puntos++;
	for (int i = 0; i < 4; i++){
		int valx = x + moveX[i];
		int valy = y + moveY[i];
		if(entradaValida(valx, valy) && !visitados[valx][valy]){
			if(tablero[valx][valy] == '.'){
				dfs(valx, valy);
			}else if(tablero[valx][valy] == 'X'){
				negroN = 1;
			}else{
				blancoN = 1;
			}
		}
	}
}

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		memset(visitados, 0, sizeof visitados);
		blanco = negro = 0;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				char temp;
				cin >> temp;
				tablero[i][j] = temp;
			}
		}
		for(int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				blancoN = negroN = 0;
				puntos = 0;
				if(tablero[i][j] == 'O'){
					blanco++;
				}else if(tablero[i][j] == 'X'){
					negro++;
				}else if(!visitados[i][j]){
					dfs(i, j);
					if(blancoN == 1 && negroN == 0){
						blanco += puntos;
					}else if(blancoN == 0 && negroN == 1){
						negro += puntos;
					}
				}
			}
		}
		cout << "Black " << negro << " White " << blanco << endl;
	}
	return 0;
}

/* Parcial 1 Arboles y Grafos UVA */

/* 383 UVA */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo(100000);
vector<int> dist(100000, 0);
vector<bool> visitados(100000, 0);

void bfs(int src){
	queue<int> q;
	q.push(src);
	visitados[src] = 1;
	dist[src] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < grafo[u].size(); i++){
			int v = grafo[u][i];
			if(visitados[v] == 0){
				visitados[v] = 1;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	int t, a, b, x, y, z, n, mx, mn, tmp, m, p;
	scanf("%d", &t);
	printf("SHIPPING ROUTES OUTPUT\n");
	for(int i = 0; i < t; i++){
		int cnt = 0, res = 0;
		vector<int> vc;
		map<int, string> mp;
		map<string, int> mp2, mp3;
		string source = "";
		scanf("%d %d %d", &m, &n, &p);
		for(int j = 0; j < m; j++){
			string s = "";
			cin >> s;
			mp[j] = s;
			mp2[s] = j;
		}
		for(int j = 0; j < n; j++){
			string val1 = "", val2 = "";
			if(j == 0){
				source += val1;
			}
			cin >> val1 >> val2;
			mp3[val1] = 1;
			mp3[val2] = 1;
			a = mp2[val1];
			b = mp2[val2];
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		cout << "DATA SET  " << i + 1 << endl << endl;
		for(int j = 0; j < p; j++){
			string val1 = "", val2 = "";
			scanf("%d", &x);
			cin >> val1 >> val2;
			bfs(mp2[val1]);
			if(mp3[val1] == 0 || mp3[val2] == 0){
				cout << "NO SHIPMENT POSSIBLE" << endl;
				continue;
			}
			res = dist[mp2[val2]];
			res = res * x * 100;
			cout << "$" << res << endl;
		}
		for(int j = 0; j < n; j++){
			grafo[j].clear();
		}
		printf("\n");
	}
	printf("END OF OUTPUT");
	return 0;
}

from sys import stdin
from collections import deque

def main():
	per = int(stdin.readline().strip())
	print("SHIPPING ROUTES OUTPUT")
	print()
	caso = 1
	for temp in range(per):
		a, b, c = [int(x) for x in stdin.readline().strip().split()]
		dic = {}
		stdin.readline().strip()
		for x in range(b):
			m, n = stdin.readline().strip().split()
			if m not in dic:
				dic[m] = [n]
			else:
				dic[m].append(n)
			if n not in dic:
				dic[n] = [m]
			else:
				dic[n].append(m)
		print("DATA SET ", caso)
		print()
		caso += 1
		for x in range(c):
			aa, bb, cc = stdin.readline().strip().split()
			pila = deque()
			vis = set()
			if bb not in dic:
				print("NO SHIPMENT POSSIBLE")
			else:
				for x in dic[bb]:
					pila.append(x)
					vis.add(x)
				cont = int(aa)
				while len(pila) > 0:
					if cc in vis:
						break
					for x in range(len(pila)):
						u = pila.popleft()
						for y in dic[u]:
							if y not in vis:
								pila.append(y)
								vis.add(y)
					cont += int(aa)
				if len(pila) > 0:
					print("$" + str(cont * 100))
				else:
					print("NO SHIPMENT POSSIBLE")
		print()
		if temp == per - 1:
			print("END OF OUTPUT")
main()


/* 679 UVA */

#include <bits/stdc++.h>

using namespace std;

int binarySearch(int n, int h, int num){
	int temp = n, high = h, l = temp * 2, r = l + 1;
	if(l <= high && r <= high){
		if(num % 2 == 0){
			int temp2 = num / 2;
			return binarySearch(r, high, temp2);
		}else{
			int temp3 = (num / 2) + 1;
			return binarySearch(l, high, temp3);
		}
	}else{
		return temp;
	}
}

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		int d, i;
		cin >> d >> i;
		int low = 1, high = pow(2, d) - 1, res = binarySearch(low, high, i);
		cout << res << endl;
	}
	cin >> casos;
}

/* 601 UVA */

#include <bits/stdc++.h>

using namespace std;

int tableroT;
int visitados[100][100];
char tablero[100][100];
bool ww = false, bw = false;

void visCero(){
	for(int i = 0; i < tableroT; i++){
		for(int j = 0; j < tableroT; j++){
			visitados[i][j] = 0;
		}
	}
}
 
void dfs( int a, int b, char c ){
	if(a < 0 || b < 0 || b >= tableroT || a >= tableroT){
		return;
	}
	if(tablero[a][b] != c || visitados[a][b] == 1){
		return;
	}
	visitados[a][b] = 1;
	dfs( a + 1, b, c );
	dfs( a - 1, b, c );
	dfs( a, b + 1, c );
	dfs( a, b - 1, c );
}

int main(){
	scanf("%d", &tableroT);
	while(tableroT > 0){
		visCero();
		ww = false;
		bw = false;
		for(int i = 0; i < tableroT; i++){
			for(int j = 0; j < tableroT; j++){
				cin >> tablero[i][j];
			}
		}
		for(int i = 0; i < tableroT; i++){
			if(tablero[i][0] == 'W'){
				dfs(i, 0, 'W');
			}
			if(tablero[0][i] == 'B'){
				dfs(0, i, 'B');
			}
		}
		for(int l = 0; l < tableroT; l++){
			if(visitados[tableroT - 1][l] == 1 && tablero[tableroT - 1][l] == 'B'){
				bw = true;
			}
			if(visitados[l][tableroT - 1] == 1 && tablero[l][tableroT - 1] == 'W'){
				ww = true;
			}
		}
		
		if(ww == true){
			printf("White has a winning path.\n");
		}else if(bw == true)
			printf("Black has a winning path.\n");
		if(bw == false && ww == false){
			for(int i = 0; i < tableroT; i++){
				for(int j = 0; j < tableroT; j++){
					visCero();
					if(tablero[i][j] == 'U' && ww == false){
						tablero[i][j] = 'W';
						for(int k = 0; k < tableroT; k++){
							if(tablero[k][0] == 'W'){
								dfs(k, 0, 'W');
							}
						}
						for(int l = 0; l < tableroT; l++){
							if( visitados[l][tableroT-1] == 1 && tablero[l][tableroT-1] == 'W' ){
								ww = true;
							}
						}
						tablero[i][j] = 'U';
					}
					visCero();
					if(tablero[i][j] == 'U' && bw == false){
						tablero[i][j] = 'B';
						for(int h = 0; h < tableroT; h++){
							if(tablero[0][h] == 'B'){
								dfs(0, h, 'B');
							}
						}
						for(int l = 0; l < tableroT; l++){
							if(visitados[tableroT - 1][l] == 1 && tablero[tableroT - 1][l] == 'B'){
								bw = true;
							}
						}
						tablero[i][j] = 'U';
					}
				}
			}
			if(ww == true){
				printf("White can win in one move.\n");
			}else if( bw == true ){
				printf("Black can win in one move.\n");
			}else{
				printf("There is no winning path.\n");
			}
		}
		scanf("%d", &tableroT);
	}
	return 0;
}

/* Taller 4 Arboles y Grafos */

/* 610 UVA */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo(1020);
bool visitados[1020];
int distancia[1020];
int low[1020];
vector<pair<int,int>> resultado;
int tiempo;

void tarjanBridges(int nodo, int padre){
	visitados[nodo] = true;
	distancia[nodo] = tiempo;
	low[nodo] = tiempo;
	tiempo++;
	for(int i = 0; i < grafo[nodo].size(); i++){
		int sig = grafo[nodo][i];
		if(sig != padre){
			if(visitados[sig] == true){
				if(distancia[nodo] > distancia[sig]){
					resultado.push_back(make_pair(nodo, sig));
				}
				low[nodo] = min(low[nodo], distancia[sig]);
			}else{
				tarjanBridges(sig, nodo);
				low[nodo] = min(low[nodo], low[sig]);
				if(low[sig] > distancia[nodo]){
					resultado.push_back(make_pair(nodo, sig));
					resultado.push_back(make_pair(sig, nodo));
				}else{
					resultado.push_back(make_pair(nodo, sig));
				}
			}
		}
	}
}

int main(){
	int printCasos = 1;
	int n, m;

	cin >> n >> m;
	while(n != 0 && m != 0){
		for(int i = 0; i < n + 5; i++){
			grafo[i].clear();
			visitados[i] = false;
			distancia[i] = -1;
			low[i] = -1;
		}
		resultado.clear();
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		tiempo = 0;
		tarjanBridges(1, -1);
		cout << printCasos << "\n\n";
		for (int i = 0; i < resultado.size(); i++){
			cout << resultado[i].first << " " << resultado[i].second << endl;
		}
		cout << "#" << endl;
		printCasos++;
		cin >> n >> m;
	}
	return 0;
}


/* 11504 UVA */

#include <bits/stdc++.h>

using namespace std;

vector<long long> grafo[100005];
vector<bool> visitados(100005, 0);
vector<long long> topo;
int n, m, counter, flag;

void kosarajuAux(int x){
	if(visitados[x] == 0){
		visitados[x] = 1;
		for(int i = 0; i < grafo[x].size(); i++){
			int nodo = grafo[x][i];
			kosarajuAux(nodo);
		}
		if(flag == 1){
			topo.push_back(x);
		}
	}
}

void kosaraju(){
	flag = 1;
	for(int i = 1; i <= n + 1; i++){
		kosarajuAux(i);
	}

	counter = 0;
	flag = 2;
	for(int i = 0; i < topo.size(); i++){
		if(visitados[topo[i]] == 0){
			counter++;
			visitados[i] = 1;
			for(int j = 0; j < grafo[i].size(); j++){
				int nodo = grafo[i][j];
				kosarajuAux(nodo);
			}
		}
	}
}



int main(){
	int casos;
	cin >> casos;
	while(casos--){
		cin >> n >> m;
		for(int i = 0; i < m; i++){
			long long a, b;
			cin >> a >> b;
			grafo[a].push_back(b);
		}
		kosaraju();
		cout << counter << endl;
	}
	return 0;
}

from sys import stdin
import sys
sys.setrecursionlimit(10 ** 6)

n = 0


def kosaraju():
    global counter

    #DFS 1
    for i in range(1, n + 1):
        kosarajuAux(i)

    for i in range(n + 1):
        visited[i] = 0

    topo.reverse()
    #for i in range(len(topo)):
        #print("%d " % topo[i], end = '')

    #print()
    counter = 0

    #DFS 2 (Modificado)
    for i in range(len(topo)):
        if visited[topo[i]] == 0:
            counter += 1
            kosarajuAux2(topo[i])

    print("%d" % counter, end = '')
    print()


def kosarajuAux(nd):
    if visited[nd] == 0:
        visited[nd] = 1
        for i in range(len(graph[nd])):
            nod = graph[nd][i]
            kosarajuAux(nod)

        topo.append(nd)

def kosarajuAux2(nd):
    if visited[nd] == 0:
        visited[nd] = 1
        for i in range(len(graph[nd])):
            nod = graph[nd][i]
            kosarajuAux(nod)


def main():
    t = int(stdin.readline())
    while t > 0:
        global n
        global graph, visited, topo
        n, m = list(map(int, input().split()))
        graph = [[] for i in range(n + 1)]
        visited = [0 for i in range(n + 1)]
        topo = []

        for i in range(m):
            x, y = list(map(int, input().split()))
            graph[x].append(y)

        kosaraju()
        t -= 1

main()

/* 11749 UVA */

#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[505];
int peso[505][505];
vector<bool> visitados(505);
int contador; 
int maxInt = 2147483647;

void reset(){
	for(int i = 0; i < 500; i++){
		grafo[i].clear();
		visitados[i] = false;
		for(int j = 0; j < 500; j++){
		    peso[i][j] = -maxInt;
		}
	}
}

void bfs(int src, int maxW){
	int nodo = src;
	visitados[nodo] = true;
	contador++;
	for(int i = 0; i < grafo[nodo].size(); i++){
		int nodoAdj = grafo[nodo][i];
		if(!visitados[nodoAdj] && peso[nodo][nodoAdj] == maxW){
			bfs(nodoAdj, maxW);
		}
	}
}

int main(){
	int n, m;

	cin >> n >> m;
	while(n != 0 && m != 0){
		reset();
		int maxW = -maxInt;
		for(int i = 0; i < m; i++){
			int a, b, w;

			cin >> a >> b >> w;
			a--; // para tener todo desde la posicion 0 de los vectores
			b--;

			grafo[a].push_back(b);
			grafo[b].push_back(a);

			if(w > peso[a][b]){
				peso[a][b] = peso[b][a] = w;
			}

			if(maxW < w){
				maxW = w;
			}
		}

		int resultado = 0;
		for(int i = 0; i < n; i++){
			if(!visitados[i]){
				contador = 0;
				bfs(i, maxW);
				if(contador >= resultado){
					resultado = contador;
				}
			}
		}
		cout << resultado << endl;
		cin >> n >> m;
	}
	return 0;
}

/* 10199 UVA */

#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[120];
bool visitados[120];
bool camara[120];
int low[120];
int high[120];
int temp;

int tarjan(int x, int p = 0){
	int corte = 0, punto = 0;
	visitados[x] = true;
	low[x] = high[x] = temp++;
	int hijos = 0;
	for(int i = 0; i < grafo[x].size(); i++){
		if(i != p){
			if(visitados[i]){
				high[x] = min(high[x], low[i]);
			}else{
				corte += tarjan(i, x);
				high[x] = min(high[x], low[i]);
				if(low[x] <= high[i] && p != 0){
					punto = 1;
					camara[x] = 1;
				}
				hijos += 1;
			}
		}
	}
	if(p == 0 && hijos > 1){
		camara[x] = punto = 1;
	}
	return corte + punto;
}

int main(){
	int printCasos = 1;
	int casos;
	cin >> casos;
	while(casos != 0){
		if(printCasos > 1){
			cout << endl;
		}
		for(int i = 1; i <= casos; i++){
			grafo[i].clear();
		}
		map<string, int> id;
		vector<string> nomCamara(casos + 1);
		for(int i = 1; i <= casos; i++){
			cin >> nomCamara[i];
			id[nomCamara[i]] = i;
		}
		int m = 1, e;

		cin >> e;
		while(e--){
			string a, b;
			cin >> a >> b;
			grafo[id[a]].push_back(id[b]);
			grafo[id[b]].push_back(id[a]);
		}
		memset(camara, 0, sizeof(camara));
		memset(visitados, 0, sizeof(visitados));
		temp = 0;
		int resultado = 0;
		for(int i = 0; i <= casos; i++){
			if(!visitados[i]){
				resultado += tarjan(i);
			}
		}
		printf("City map #%d: %d camera(s) found\n", printCasos++, resultado);
		vector<string> resul;
		for(int i = 0; i <= casos; ++i){
			if(camara[i]){
				resul.push_back(nomCamara[i]);
			}
		}
		sort(nomCamara.begin(), nomCamara.end());

		for(int i = 0; i < nomCamara.size(); ++i){
			cout << nomCamara[i] << endl;
		}

		cin >> casos;
	}
	return 0;
}

/* 10765 UVA */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo(10001);
vector<int> visitados(10001, 0);
vector<int> componentes(10001);
int n, m, t;

bool cmp(const pair<int,int> A, const pair<int,int> B){
	if(A.second > B.second){
		return true;
	}
	if(A.second == B.second && A.first < B.first){
		return true;
	}
	return false;
}

int dfs(int x, int p){
	int minimo = visitados[x] = ++t;
	componentes[x] = 1;
	for(int i = 0; i < grafo[x].size(); i++){
		int y = grafo[x][i];
		if(y != p){
			if(visitados[y]){
				minimo = min(minimo, visitados[y]);
			}else{
				int tempMin = dfs(y, x);
				minimo = min(minimo, visitados[tempMin]);
				if(tempMin >= visitados[x]){
					componentes[x]++;
				}
			}
		}
	}
	return minimo;
}

int main(){
	int n, m;
	cin >> n >> m;
	while(n != 0 && m != 0){
		for(int i = 0; i < n; i++){
			grafo[i].clear();
		}
		int a, b;
		cin >> a >> b;
		while(a >= 0 && b >= 0){
			grafo[a].push_back(b);
			grafo[b].push_back(a);
			cin >> a >> b;
		}
		dfs(0,0);
		componentes[0]--;
		vector<pair<int, int>> resultado;
		for(int i = 0; i < n; i++){
			resultado.push_back(make_pair(i, componentes[i]));
		}
		sort(resultado.begin(), resultado.end(), cmp);
		for(int i = 0; i < m; i++){
			cout << resultado[i].first << " " << resultado[i].second << endl;
		}
		cout << endl;
		cin >> n >> m;
	}
	return 0;
}

/* Taller 5 Arboles y Grafos */

/* 12519 UVA */


#include <climits>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<vector<pair<int, int> > > adj(101);
vector<int> p(101);
vector<int> d(101);

bool bellmanFord(int s, int n){
  int i, j, k, v, peso;
  bool flag;

  for(i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
  for(k = 0; k < n - 1; ++k){
    flag = false;
    
    for(i = 0; i < n; i++){
      for(j = 0; j < adj[i].size(); ++j){
    	v = adj[i][j].first;
    	peso = adj[i][j].second;
    	if(d[i] != INT_MAX && d[i] + peso < d[v]){
    	  d[v] = d[i] + peso;
    	  p[v] = i;
    	  flag = true;
    	}
      }
    }

    if(!flag)
      break;
  }
  
  for(i = 0; i < n; i++){
    for(j = 0; j < adj[i].size(); ++j){
      v = adj[i][j].first;
      peso = adj[i][j].second;
      if(d[i] != INT_MAX && d[i] + peso < d[v]){
          return false;
      }
    }
  }

  return true;
}

int main(){
	int nodos, aristas;

	cin >> nodos >> aristas;
	while(nodos != 0 && aristas != 0){
		int a, b, peso;
		for(int i = 0; i < aristas; i++){
			cin >> a >> b >> peso;
			adj[a - 1].push_back(make_pair(b - 1, peso));
			adj[b - 1].push_back(make_pair(a - 1, -peso));
		}
		
		adj.resize(nodos);
		p.resize(nodos);
		d.resize(nodos);
		
		bool res = bellmanFord(0, nodos);
		
		adj.clear();
		p.clear();
		d.clear();
		adj.resize(101);
		p.resize(101);
		d.resize(101);

		if(res){
			cout << "N" << endl;
		}else{
			cout << "Y" << endl;
		}
		cin >> nodos >> aristas;
	}
	return 0;
}

/* 12047 UVA */
#include <climits>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n;
vector<vector<pair<int, int> > > adj(50000);
vector<vector<pair<int, int> > > radj(50000);
vector<int> p(50000);
vector<int> d(50000);
vector<int> rp(50000);
vector<int> rd(50000);

void inicializar(int s){
  for(int i = 0; i < n; ++i){
    d[i] = INT_MAX;
    p[i] = -1;
  }

  d[s] = 0;
}

void dijkstra(int s){
  int i, j, k, u, v, peso, costo;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cola;
  
  inicializar(s);
  cola.push(make_pair(0, s));

  while(!cola.empty()){
    costo = cola.top().first;
    u = cola.top().second;
    cola.pop();

    if(costo == d[u]){
      for(j = 0; j < adj[u].size(); ++j){
      	v = adj[u][j].first;
      	peso = adj[u][j].second;
      	if(d[u] != INT_MAX && d[u] + peso < d[v]){ 
      	  d[v] = d[u] + peso;
      	  p[v] = u;
      	  cola.push(make_pair(d[v], v));
      	}
      }
    }
  }
}

void dijkstraR(int s){
  int i, j, k, u, v, peso, costo;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > cola;
  
  inicializar(s);
  cola.push(make_pair(0, s));

  while(!cola.empty()){
    costo = cola.top().first;
    u = cola.top().second;
    cola.pop();

    if(costo == rd[u]){
      for(j = 0; j < radj[u].size(); ++j){
      	v = radj[u][j].first;
      	peso = radj[u][j].second;
      	if(rd[u] != INT_MAX && rd[u] + peso < rd[v]){ 
      	  rd[v] = rd[u] + peso;
      	  rp[v] = u;
      	  cola.push(make_pair(rd[v], v));
      	}
      }
    }
  }
}

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		int n, m, s, t, p, aux1, aux2, peso;
		cin >> n >> m >> s >> t >> p;
		for(int i = 0; i < m; i++){
			cin >> aux1 >> aux2 >> peso;
			adj[aux1].push_back(make_pair(aux2, peso));
			radj[aux2].push_back(make_pair(aux1, peso));
		}
		dijkstra(s);
		dijkstraR(t);
		
		int res = -1;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < (int)adj[i].size(); j++){
				int arista = adj[i][j].second;
				int vertice = adj[i][j].first;
				int totalCost = arista + d[i] + rd[vertice];
				if((totalCost <= p) && (arista > res)){
					res = arista;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

/* 12319 UVA */

from sys import stdin

grafo = []
grafoN = []

def floydWarshall(w):
    global grafo, grafoN
    n = len(grafo)
    d = [[float("inf") for j in range(n)] for i in range(n)]
    next = [[-1 for j in range(n)] for i in range(n)]

    for i in range(n):
        for j in range(n):
            if(w == 1):
                d[i][j] = grafo[i][j]
            else:
                d[i][j] = grafoN[i][j]
            next[i][j] = j
            
    for i in range(n):
        d[i][i], next[i][i] = 0, i

        
    for k in range(0, n):
        for i in range(0, n):
            for j in range(0, n):
                if d[i][k] + d[k][j] < d[i][j]:
                    d[i][j] = d[i][k] + d[k][j]
                    next[i][j] = next[i][k]
    return d, next

def main():
	global grafo, grafoN
	lectura = stdin.readlines()
	i = 0
	grafo = [[float("inf") for j in range(101)] for i in range(101)]
	grafoN = [[float("inf") for j in range(101)] for i in range(101)]
	while(i < len(lectura) and lectura[i] != 0):
		tam = int(lectura[i])
		i += 1
		n = 0
		while(n < 2):
			j = 0
			while(j < tam):
				k = 0
				temp = list(map(int, lectura[i].split()))
				lectura[i] = temp
				while(k < len(lectura[i])):
					if(n == 0):
						if(k == 0):
							yonose = int(lectura[i][k])
							grafo[j][yonose - 1] = 0
						else:
							yonose = int(lectura[i][k])
							grafo[j][yonose - 1] = 1
					else:
						if(k == 0):
							yonose = int(lectura[i][k])
							grafoN[j][yonose - 1] = 0
						else:
							yonose = int(lectura[i][k])
							grafoN[j][yonose - 1] = 1
					k += 1
				j += 1
				i += 1
			n += 1
		print(lectura[i])
		a, b = lectura[i].split()
		a = int(a)
		b = int(b)
		
		d1, next1 = floydWarshall(1)
		d2, next2 = floydWarshall(2)
		
		flag = True

		for m in range(tam):
			for z in range(tam):
				formula = a * d1[m][z] + b
				if(formula < d2[m][z]):
					flag = False
					break
			if(not flag):
			    break

		if(flag):
			print("Yes")
		else:
			print("No")
		i += 1

main()

/* 10369 UVA */

import sys
import math

MAX = 510
INF = 2100000000

x = [0 for i in range(MAX)]
y = [0 for i in range(MAX)]
used = []
dist = []

def dist2(i, j):
	return (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i])

def Prim():
	global used, dist
	used = [0 for i in range(MAX)]
	dist = [INF for i in range(MAX)]
	cur = 0
	dist[cur] = 0
	used[cur] = 1

	for i in range(1, p):
		for j in range(1, p):
			if(not used[j] and (dist2(cur, j) < dist[j])):
				dist[j] = dist2(cur, j)

		min = INF
		for j in range(0, p):
			if(not used[j] and (dist[j] < min)):
				min = dist[j]
				cur = j
		used[cur] = 1

n = int(input())

for i in range(n):
	sp = input().split()
	s = int(sp.pop(0))
	p = int(sp.pop(0))

	for j in range(p):
		xy = input().split()
		x[j] = int(xy.pop(0))
		y[j] = int(xy.pop(0))

	Prim()
	dist = sorted(dist[0:p]) + dist[p:]
	print("{:.2f}".format(math.sqrt(1.0 * dist[p-s])))


/* 10842 UVA */

#include <bits/stdc++.h>

using namespace std;

vector<int> grafo[110];
vector<int> p(110);

int n, m, pa;

void Prim(){
	vector<int> d(110);
	vector<bool> visitados(110, false);
	int v, mi;

	for(int i = 0; i <= n; i++){
		d[i] = p[i] = -1;
	}

	d[0] = 0;
	pa = 0;

	for(int i = 0; i < n; i++){
		mi = -1;
		for(int j = 0; j < n; j++){
			if(!visitados[j] && d[j] > mi){
				mi = d[i];
				v = j;
			}
		}
		visitados[v] = true;
		pa += mi;
		for(int j = 0; j < n; j++){
			if(!visitados[j] && d[j] < grafo[v][j]){
				p[j] = v;
				d[j] = grafo[v][j];
			}
		}
	}
}

int main(){
	int printCasos = 1;
	int casos;
	cin >> casos;
	while(casos--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				grafo[i][j] = -1;
			}
		}
		while(m--){
			int a, b, c;
			cin >> a >> b >> c;
			if(a != b){
				grafo[a][b] = grafo[b][a] = max(c, grafo[a][b]);
			}
		}
		Prim();

		int res = INT_MAX;
		for(int i = 1; i < n; i++){
			res = min(res, grafo[i][p[i]]);
		}
		cout << "Case #" << printCasos++ << ": " << res << endl;
	}
	return 0;
}

/* Parcial 2 Arboles y Grafos */

/* 1160 UVA */
from sys import stdin
import math

p, rango = [0 for _ in range(100001)], [0 for _ in range(100001)]
def makeSet(v):
    p[v], rango[v] = v, 0

def findSet(v):
    ans = None
    if v == p[v]: ans = v
    else:
        p[v] = findSet(p[v])
        ans = p[v]
    return ans

def unionSet(u, v):
    u, v = findSet(u), findSet(v)

    if u != v:
        if rango[u] < rango[v]: u, v = v, u
        p[v] = u
        if rango[u] == rango[v]: rango[u] += 1

def isSameSet(u, v):
	x = findSet(u)
	y = findSet(v)
	return x == y

def main():
	result = 0
	casos = stdin.readline().strip()
	while(casos != ""):
		if(casos == "-1"):
			p, rango = [0 for _ in range(100001)], [0 for _ in range(100001)]
			print(result)
			print()
		lista = casos.split()
		a = int(lista.pop(0))
		b = int(lista.pop(0))
		if(isSameSet(a, b)):
			result += 1
		else:
			unionSet(a, b)
		casos = stdin.readline().strip()


main()

/* 13127 UVA */
from heapq import heappop, heappush

INF = float('inf')
def dijkstra(G, pol):
    d, p = [INF for i in range(len(G))], [-1 for i in range(len(G))]
    heap = []
    for i in pol:
        d[i] = 0
        heappush(heap, (d[i], i))
    while len(heap) != 0:
        costo, u = heappop(heap)
        if costo == d[u]:
            for v, w in G[u]:
                if d[v] > d[u] + w:
                    d[v], p[v] = d[u] + w, u
                    heappush(heap, (d[v], v))
    return d, p


def main():
	lectura = stdin.readline()
	while(lectura != ""):
		n, m, b, p = list(map(int, lectura.split()))
		grafo = [[] for i in range(n)]
		for i in range(m):
			u, v, t = list(map(int, input().split()))
			grafo[u].append((v, t))
			grafo[v].append((u, t))
		bancos = list(map(int, input().split()))
		policias = list(map(int, input().split()))

		dist, peso = dijkstra(grafo, policias)
		



/* 11280 UVA */
#include <bits/stdc++.h>

using namespace std;

unordered_multimap<int, pair<int, int>> grafo;
unordered_map<string, int> ciudades;
map<int, string, greater<int>> ciudadesR;
unordered_map<int, int> distancia;
int INF = INT_MAX / 2;

void bellmanFord(int n){
	distancia[ciudades["Calgary"]] = 0;
	int itF, itM, itS;
	for(int z = 1; z <= n; z++){
		for(map<int, string>:: iterator it = ciudadesR.begin(); it != ciudadesR.end(); it++){
			itM = it->first;
			// lo hago igual que en geekforgeeks https://www.geeksforgeeks.org/unordered_multimap-equal_range-function-in-c-stl/
			auto itr = grafo.equal_range(itM); 
			for(auto itra = itr.first; itra != itr.second; itra++){
				itF = itra->second.first;
				itS = itra->second.second;
				if(distancia[itS] > distancia[itM] + itF){
					distancia[itS] = distancia[itM] + itF;
				}
			}
		}
	}
}

int main(){
	int casos, printCasos = 1;
	cin >> casos;
	while(casos--){
		int n;
		string nomCiudad;
		int nodo, peso;
		string c1, c2;
		int query;
		int numCiudad = 1;

		cin >> n;

		while(n--){
			//lectura ciudades
			cin >> nomCiudad;
			ciudades.insert({nomCiudad, numCiudad});
			ciudadesR.insert({numCiudad, nomCiudad});
			distancia.insert({numCiudad, INF});
			numCiudad++;
		}

		cin >> nodo;

		while(nodo--){
			//crear grafo
			cin >> c1 >> c2 >> peso;
			grafo.insert({ciudades[c1], {peso, ciudades[c2]}});
		}

		cin >> query;
		cout << "Scenario #" << printCasos++ << endl;
		while(query--){
			//queries posibles
			int cantParadas;
			cin >> cantParadas;
			bellmanFord(cantParadas + 1);

			if(distancia[ciudades["Fredericton"]] == INF){
				cout << "No satisfactory flights" << endl;
			}else{
				cout << "Total cost of flight(s) is $" << distancia[ciudades["Fredericton"]] << endl;
			}

			for(unordered_map<int, int>::iterator it = distancia.begin(); it != distancia.end(); it++){
				distancia[it->first] = INF;
			}
		}
		grafo.clear();
		ciudades.clear();
		ciudadesR.clear();
		cout << endl;
	}
	return 0;
}

/* Parcial 3 Arboles y Grafos*/

/* 699 UVA */
#include <bits/stdc++.h>

using namespace std;

map<int,int> arbol;

void crearArbol(int pos, int num){
	if(num == -1){
		return;
	}
	if(arbol.count(pos)){
		n[pos] += num;
	}else{
		n[pos] = num;
	}
	int izq, der;
	cin >> izq;
	crearArbol(pos - 1, izq);
	cin >> der;
	crearArbol(pos + 1, der);
}

int main(){
	int i, casos = 0;

	while((cin >> i) && (i != -1)){
		map<int,int> arbol;
		crearArbol(0, i);
		cout << "Case " << (++casos) << ":" << endl;
		map<int,int>::iterator it;
		map<int,int>::iterator end = arbol.end();
		end--;
		for(it = arbol.begin(); it != end; it++){
			cout << it->second << " ";
		}
		cout << it->second << endl << endl;
	}
	return 0;
}

/* 10459 UVA */

#include <bits/stdc++.h>

using namespace std;

void worstRoots(vector<vector<int>>& tree, set<int>& peores, int padre, int v, int distancia, int& radio, int& pos){
	int u;
	++distancia;

	if(distancia > radio){
		radio = distancia;
		peores.clear();
		peores.insert(v);
		pos = v;
	}else if(distancia == radio){
		peores.insert(v);
	}

	for(int i = 0; i < tree[v].size(); ++i){
		u = tree[v][i];
		if(u != padre){
			worstRoots(tree, peores, v, u, distancia, radio, pos);
		}
	}
}

void centro(vector<vector<int>>& tree, set<int>& mejores){
	int v, nivelMax;
	queue<int> cola;
	vector<int> grado, nivel;

	nivelMax = 0;
	nivel = vector<int>(tree.size(), 0);
	grado = vector<int>(tree.size(), 0);
	for(int i = 1; i < tree.size(); ++i){
		grado[i] = tree[i].size();
	}

	for(int i = 1; i < tree.size(); ++i){
		if(grado[i] == 1){
			cola.push(i);
		}
	}

	while(!cola.empty()){
		v = cola.front();
		cola.pop();

		for(int i = 0; i < tree[v].size(); ++i){
			--grado[tree[v][i]];
			if(grado[tree[v][i]] == 1){
				cola.push(tree[v][i]);
				nivel[tree[v][i]] = nivel[v] + 1;
				nivelMax = max(nivelMax, nivel[tree[v][i]]);
			}
		}
	}

	for(int i = 1; i < tree.size(); ++i){
		if(nivel[i] == nivelMax){
			mejores.insert(i);
		}
	}
}

void recorridoArbol(vector<vector<int>>& tree){
	int radio, pos;
	set<int> mejores, peores, temp;
	set<int>::iterator it, jt;
	
	centro(tree, mejores);

	jt = mejores.end();
	--jt;
	cout << "Best Roots  : ";
	for(it = mejores.begin(); it != mejores.end(); ++it){
		if(it == jt){
			cout << (*it) << endl;
		}else{
			cout << (*it) << " ";
		}
	}

	radio = pos = 0;
	worstRoots(tree, peores, -1, 1, -1, radio, pos);
	worstRoots(tree, temp, -1, pos, -1, radio, pos);

	for(it = temp.begin(); it != temp.end(); ++it){
		peores.insert((*it));
	}

	jt = peores.end();
	--jt;
	cout << "Worst Roots : ";
	for(it = peores.begin(); it != peores.end(); ++it) {
		if(it == jt){
			cout << (*it) << endl;
		}else{
			cout << (*it) << " ";	
		}
	}
}

int main(){
	int levels, cant, numero;
	vector<vector<int>> tree;

	while(cin >> levels){
		tree = vector<vector<int>>(levels + 1, vector<int>());
		for(int i = 1; i <= levels; ++i){
			cin >> cant;
			for(int j = 0; j < cant; ++j){
				cin >> numero;
				tree[i].push_back(numero);
			}
		}
		recorridoArbol(tree);
	}

	return 0;
}

/* 12086 UVA */

from sys import stdin, stdout
for i in range(3):
	a = stdin.readline()
	a = int(a)
	pot = []
	if a == 0:
		break
	for j in range(a):
		b = stdin.readline()
		pot.append(int(b))

	stdout.write("Case " + str(i + 1) + ':' + '\n')

	com = stdin.readline()
	while(com != "END"):
		dastor = com.split()
		if dastor[0] == "S":
			pot[int(dastor[1]) - 1] = int(dastor[2])
		elif dastor[0] == "M":
			first = int(dastor[1])
			second = int(dastor[2])
			sum = 0
			for q in range(first - 1, second):
				sum = sum + pot[q]
			stdout.write(str(sum) + '\n')
		com = stdin.readline()
	stdout.write("\n")

/* 615 UVA */

#include <bits/stdc++.h>

using namespace std;

map<int,int> arbol;
set<int> nodo;

void limpiar(){
	arbol.clear();
	nodo.clear();
	return;
}

int buscarRaiz(int nodo){
	if(arbol[nodo] == nodo){
		return nodo;
	}else{
		return arbol[nodo] = buscarRaiz(arbol[nodo]);
	}
}

int main(){
	int ef, es, count = 0, nd;
	bool esArbol = true;
	scanf("%d %d", &ef, &es);
	while(ef < 0 && es < 0){
		if(ef == 0 && es == 0){
			count++;
			int cntRaiz = 0;
			if(esArbol){
				set<int>::iterator it;
				for(it = nodo.begin(); it != nodo.end(); it++){
					nd = *it;
					if(arbol[nd] == nd){
						cntRaiz++;
					}
				}
			}
			esArbol = (cntRaiz == 1);
			if(nodo.size() == 0){
				esArbol = true;
			}
			if(esArbol){
				printf("Case %d is a tree.\n", count);
			}else{
				printf("Case %d is not a tree.\n", count);
			}
			esArbol = true;
			limpiar();
			continue;
		}
		if(!esArbol){
			continue;
		}
		if(nodo.find(es) == nodo.end()){
			nodo.insert(es);
			arbol[es] = es;
		}
		if(nodo.find(ef) == nodo.end()){
			nodo.insert(ef);
			arbol[ef] = ef;
		}
		int raiz = buscarRaiz(es);
		if(raiz != es || raiz == buscarRaiz(ef)){
			esArbol = false;
			continue;
		}
		arbol[es] = ef;
		scanf("%d %d", &ef, &es);
	}
	return 0;
}

/* Proyecto AGRA 1048 UVA */

/*
Autor: Santiago Torres Rincón
Codigo: 8940234
Frase de Compromiso: Como miembro de la comunidad académica de la Pontificia Universidad Javeriana Cali me comprometo a seguir los más altos estándares de integridad académica.
*/

#include <bits/stdc++.h>

using namespace std;

int tiquetes, cantParadas;
int dist[210][11];
pair<int,int> predecesor[210][11];
int resTiquetes[210][11]; //Matriz de datos que guardan los tiquetes que se utilizan para cada uno de los itinerarios en el orden en el que se utilizan
bool vis[210][11];
int ciudades[21];
int peso[21];
vector<int> vectTiquetes[21]; //Vector con los tiquetes y las ciudades que aparecen en el tiquete junto con el orden de aparicion de las ciudades en la entrada

void busqueda(int s, int t){
	/*
	Entrada: Valor inicial para la busqueda del camino mas corto y el valor que representa en el grafo(1 porque es el primero en el grafo)
	
	Salida: No tiene salida puesto que modifica las estructuras globales.
	
	Descripcion: Esta funcion lee el primer nodo dentro del vector de ciudades y se pone explicito que es el primer valor dentro del grafo, es decir el nodo de inicio
	para la busqueda del camino mas corto. Dentro del algoritmo se utilizan 2 colas, la primera guarda ese nodo inicial y la segunda la posicion en la que se encuentra en el grafo
	Despues de eso pasa por todo los tiquetes revisando que encuentre el valor u como primera instancia para poder usar el tiquete ya que no se puede usar un tiquete desde un nodo
	intermedio solo desde el primer nodo. Posteriormente recorre el vectTiquetes para revisar las demas ciudades dentro del tiquete, para asi calcular la distancia mas corta posible
	haciendo las relajaciones necesarias. Finalmente hace la relajacion e introduce los valores que se usaron como nuevos nodos para revisar y procesar para seguir usandolos como nodos
	de inicio para la busqueda.
	*/
	memset(dist, 100, sizeof(dist));
	queue<int> quex, quey;
	dist[s][t] = 0;
	predecesor[s][t] = make_pair(-1, -1);
	resTiquetes[s][t] = -1;
	vis[s][t] = 1;
	quex.push(s);
	quey.push(t);
	while(quex.size()){
		int u = quex.front();
		quex.pop();
		int a = quey.front();
		quey.pop();
		vis[u][a] = 0;
		for(int i = 0; i < tiquetes; i++){
			if(vectTiquetes[i][0] == u){
				int v = u;
				int b = a;
				for(int k = 1; k < vectTiquetes[i].size(); k++){
					v = vectTiquetes[i][k];
					if(v == ciudades[b]){ //Revisa que no esten en la misma ciudad, si es la misma pasa a la siguiente.
						b++;
					}
					if(dist[v][b] > dist[u][a] + peso[i]){
						dist[v][b] = dist[u][a] + peso[i];
						predecesor[v][b] = make_pair(u, a);
						resTiquetes[v][b] = i;
						if(!vis[v][b]){ //Revisa si no se ha visitado antes y lo marca como visitado y agrega los valores a las colas para que sean procesados.
							quex.push(v);
							quey.push(b);
							vis[v][b] = 1;
						}
					}
				}
			}
		}
	}
}

int main(){
	int casos = 0;
	while(scanf("%d", &tiquetes) && tiquetes != 0){
		map<int,int> ciudadUsada;
		int count = 0;
		for(int i = 0; i < tiquetes; i++){
			scanf("%d", &peso[i]);
			int cantCiudades;
			scanf("%d", &cantCiudades);
			vectTiquetes[i].clear();//Se asegura que no hayan valores dentro haciendo una limpieza.
			for(int j = 0; j < cantCiudades; j++){
				int a;
				scanf("%d", &a);
				if(ciudadUsada[a] == 0){ //Se lee la ciudad y se revisa que no se haya leido previamente, si no se ha leido se aumenta el contador de los nodos presentes.
					ciudadUsada[a] = ++count;
				}
				vectTiquetes[i].push_back(ciudadUsada[a]); //Guarda la ciudad que se leyo con el valor de aparicion para poder utilizarlo mas adelante sin perder el tiquete al que pertenece.
			}
		}
		int itinerarios;
		scanf("%d", &itinerarios);
		++casos;
		for(int i = 0; i < itinerarios; i++){
			scanf("%d", &cantParadas);
			for(int j = 0; j < cantParadas; j++){
				scanf("%d", &ciudades[j]);
				ciudades[j] = ciudadUsada[ciudades[j]]; //Guarda la ciudad que se utilizo en con el valor en el que aparecio en la entrada
			}
			ciudades[cantParadas] = 0;
			busqueda(ciudades[0], 1);
			cout << "Case " << casos << ", Trip " << i + 1 << ":" << " Cost = " << dist[ciudades[cantParadas - 1]][cantParadas] << endl;

			int u = ciudades[cantParadas - 1], a = cantParadas;
			vector<int> vt;
			while(resTiquetes[u][a] >= 0){
				/*
				Esta funcion busca cuales son los tiquetes que se utilizaron y los inserta dentro del vector para imprimir, luego busca cual es el predecesor de ese nodo para tambien
				agregarlo dentro del vector y poder imprimir todos los tiquetes usados. Estos tiquetes estan siendo introducidos en orden del ultimo usado al primer usado.
				*/
				vt.push_back(resTiquetes[u][a]);
				int v = predecesor[u][a].first;
				int b = predecesor[u][a].second;
				u = v;
				a = b;
			}
			cout << "  Tickets used: ";
			for(int i = vt.size(); i >= 1; i--){
				printf("%d", vt[i - 1] + 1);
				if(i - 1){
					printf(" ");
				}
			}
			cout << endl;
		}
	}
	return 0;
}

/*
Complejidad:
    O(I(E logV))
Explicacion:
Esta complejidad se logra porque se usa la implementacion del algoritmo de Dijkstra con modificaciones para adaptarse al ejercicio y utilizando una cola de prioridad implicita
ya que en las colas solo se usan los valores que no se hayan usado previamente y que sean menores a los valores que se encuentran, un minheap. La E representa el numero de aristas
dentro del grafo y la V representa la cantidad de vertices dentro del grafo. Por ultimo la I representa la cantidad de itinerarios que se van a usar ya que dependiendo de cuantos sean
de eso dependera cuantas veces se tiene que recorrer el grafo y usar el algoritmo de Dijkstra.
*/


/*Analisis y Diseño de Algoritmos*/

/*Tarea 1*/

/*12390 UVA - Distributing Ballot Boxes*/
from sys import stdin

A,N,B = None,None,None

def ok(size):
  b,n = 0,0
  while b<=B and n!=N:
    bc,rem = A[n]//size,A[n]%size
    if rem!=0: bc += 1
    b,n = b+bc,n+1
  return b<=B

def solve():
  low,hi = 0,max(A)
  while low+1!=hi:
    mid = low+((hi-low)>>1)
    if ok(mid): hi = mid
    else: low = mid
  return hi

def main():
  global A,N,B
  N,B = map(int, stdin.readline().split())
  while N!=-1:
    A = [ int(stdin.readline()) for _ in range(N) ]
    stdin.readline()
    print(solve())
    N,B = map(int, stdin.readline().split())

main()

/*10567 UVA - Helping Fill Bates*/
from sys import stdin

text,dist = None,[ list() for _ in range(256) ]

def lowerbound(x, p):
  lo, up = 0, len(p)
  while lo < up:
    mid = low+((hi-low)>>1)
    if x <= p[mid]:
      up = mid
    else:
      lo = mid+1
  return p[lo]

def solve(p):
  ans = (-1,-1,-1)
  r = 0
  f,l = -1,-1
  flag = False
  for i in range(len(p)):
    res = lowerbound(r, dist[p[i]])
    r = res + 1
    if r == 0:
      f = dist[p[r]]
    elif i == (len(p)-1):
      l = r
      flag = True
  ans = (flag,f,l)
  return ans
  
def main():
  global text,dist
  text = stdin.readline().strip()
  for i in range(len(text)): dist[ord(text[i])].append(i)
  tcnt = int(stdin.readline())
  while tcnt!=0:
    p = stdin.readline().strip()
    ans,first,last = solve(p)
    if ans: print('Matched {0} {1}'.format(first, last))
    else: print('Not matched')
    tcnt -= 1

main()

/*10382 UVA - Leaps Tall Buildings*/
from sys import stdin
from math import sqrt,sin,cos,pi,floor

N,city = None,None
A,EPS = 9.8,1e-5

# https://stackoverflow.com/questions/29246455/python-setting-decimal-place-range-without-rounding
# def truncate(f, n): return floor(f * 10 ** n) / 10 ** n

def solve():
  ans = (-1,-1)
  return ans

def main():
  global N,city
  line = stdin.readline()
  while len(line)!=0:
    N,city = int(line),list()
    for _ in range(N):
      city.append(tuple(map(float,stdin.readline().split())))
    angle,vel = solve()
    print('{0:.2f} {1:.2f}'.format(angle, vel))
    line = stdin.readline()

main()

/*787 UVA - Maximum Sub-sequence Product*/
from sys import stdin

def solve(a):
  res = a[0]
  if a[0] < 0:
  	negativos = a[0]
  else:
  	negativos = 0
  if a[0] >= 0:
  	positivos = a[0]
  else:
  	positivos = 0
	
  for i in range(1, len(a)):
  	n = a[i]
  	if n == 0:
  		res,negativos,positivos = max(res,0),0,0
  	elif n < 0:
  		negtemp, postemp = positivos*n, negativos*n #para mantener los numeros en cada lado
  		res = max(res, n, postemp)
  		positivos,negativos = postemp, min(n, negtemp)
  	else:
  		negtemp, postemp = negativos*n, positivos*n
  		res = max(res, n, postemp)
  		positivos, negativos = max(n, postemp), negtemp  
  return res

def main():
  test = list()
  for l in stdin.readlines():
    for x in map(int, l.split()):
      if x==-999999:
        print(solve(test))
        test = list()
      else: test.append(x)
  
main()


/*Tarea 2*/

/*11002 - Towards Zero*/
from sys import stdin

board,N,rows = None,None,None

def rho(r, c):
  ans = None
  if r>=N: ans = [c, c+1]
  else:
    ans = list()
    if c!=0: ans.append(c-1)
    if c!=r: ans.append(c)
  return ans

def solve_aux(r, c, x, memo):
  ans,key = None,(r, c, x)
  if key in memo: ans = memo[key]
  else:
    if r==0: ans = abs(board[0][0])==abs(x)
    else:
      ans,n,NXT = False,0,rho(r, c)
      while ans==False and n!=len(NXT):
        ans = solve_aux(r-1, NXT[n], x+board[r][c], memo) or \
          solve_aux(r-1, NXT[n], x-board[r][c], memo)
        n += 1
    memo[key] = ans
  return ans

def solve():
  ans,n,found,memo = None,0,False,dict()
  while found==False:
    found = solve_aux(rows-1, 0, n, memo) or solve_aux(rows-1, 0, -n, memo)
    if found: ans = n
    n += 1
  return ans

def main():
  global board,N,rows
  N = int(stdin.readline())
  while N!=0:
    rows = (N<<1)-1
    board = [ list(map(abs, map(int, stdin.readline().split()))) for _ in range(rows) ]
    print(solve())
    # print(rho(rows-1, 0))
    # print(rho(N, 0))
    # print(rho(1, 0))
    N = int(stdin.readline())

main()

/*10069 - Distinct Subsequences*/
from sys import setrecursionlimit
from sys import stdin
setrecursionlimit(1<<24)

def phi_memo(n, m, memo):
  ans,key = None,(n, m)
  if key in memo: ans = memo[key]
  else:
    if m==0: ans = 1
    elif m>n: ans = 0
    else:
      ans = phi_memo(n-1, m, memo)
      if T[n-1]==P[m-1]:
        ans += phi_memo(n-1, m-1, memo)
    memo[key] = ans
  return ans

def main():
    global T, P
    casos = int(stdin.readline())
    while casos != 0:
        memo = {}
        T = stdin.readline().rstrip('\n')
        P = stdin.readline().rstrip('\n')
        print(phi_memo(len(T), len(P), memo))
        casos -= 1

main()