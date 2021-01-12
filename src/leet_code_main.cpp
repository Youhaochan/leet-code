#include <leet_code.h>

int main()
{
	/**最易懂的贪心算法*/
	Leet_Code lc;
	string S = "mhnbzxkwzxtaanmhtoirxheyanoplbvjrovzudznmetkkxrdmr";
	vector<int> indexes = {46,29,2,44,31,26,42,9,38,23,36,12,16,7,33,18};
	vector<string> sources = {"rym","kv","nbzxu","vx","js","tp","tc","jta","zqm","ya","uz","avm","tz","wn","yv","ird"};
	vector<string> targets = {"gfhc","uq","dntkw","wql","s","dmp","jqi","fp","hs","aqz","ix","jag","n","l","y","zww"};
	int numRows = 3;
	std::cout<<lc.findReplaceString( S, 
									indexes, 
									sources, 
									targets);

	return 1;
}


           