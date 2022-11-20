#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

map<string, int> vars_i;
map<string, vector<int>> vars_v;

bool is_num(string s) {
    int k = s[0] - '0';
    return s.size() == 1 && k >= 0 && k <= 9 ? true : false;
}

void print_vec(vector<int> v) {
    cout << "[ ";
    rep(i, v.size()) cout << v[i] << " ";
    cout << "]" << endl;
}

void calc_int(vector<string> data, int &n, bool plus);
void calc_vec(vector<string> data, vector<int> &v, bool plus);

int main() {

    int n;
    cin >> n;

    vector<vector<string>> order(n);
    rep(i, n) {
        while(order[i].empty() || order[i].back() != ";") {
            string input;
            cin >> input;
            order[i].push_back(input);
        }
    }

    rep(i, n) {
        
        if (order[i].front() == "int") {
            int new_var = 0;
            string new_name = order[i][1];
            order[i].erase(order[i].begin(), order[i].begin()+3);
            calc_int(order[i], new_var, true);
            vars_i[new_name] = new_var;
        }

        if (order[i].front() == "print_int") {
            int output = 0;
            order[i].erase(order[i].begin());
            calc_int(order[i], output, true);
            cout << output << endl;
        }

        if (order[i].front() == "vec") {
            vector<int> new_vec;
            string new_name = order[i][1];
            order[i].erase(order[i].begin(), order[i].begin()+3);
            calc_vec(order[i], new_vec, true);
            vars_v[new_name] = new_vec;
        }

        if (order[i].front() == "print_vec") {
            vector<int> output;
            order[i].erase(order[i].begin());
            calc_vec(order[i], output, true);
            print_vec(output);
        }

    }

}

void calc_int(vector<string> data, int &n, bool plus) {
    rep(i, data.size()) {
        if (i%2 == 0) {
            if (is_num(data[i])) n += plus ? stoi(data[i]) : -1 * stoi(data[i]);
            else n += plus ? vars_i[data[i]] : -1 * vars_i[data[i]];
        } else plus = data[i] == "+";
    }
}

void calc_vec(vector<string> data, vector<int> &v, bool plus) {
    rep(i, data.size()) {
        if (v.empty()) {
            
            if (data[i] != "[") v = vars_v[data[i]];

            else {
                i++;
                while (data[i] != "]") {
                    if (is_num(data[i])) v.push_back(stoi(data[i]));
                    else if (data[i] != ",") v.push_back(vars_i[data[i]]);
                    i++;
                }
            }

        } else {

            if (data[i] == "+") plus = true;
            else if (data[i] == "-") plus = false;

            else if (data[i] != "[") {
                rep(j, vars_v[data[i]].size()) v[j] += plus ? vars_v[data[i]][j] : -1 * vars_v[data[i]][j];

            } else {
                int j=0; i++;
                while (data[i] != "]") {

                    if (is_num(data[i])) {
                        v[j] += plus ? stoi(data[i]) : -1 * stoi(data[i]);
                        j++;
                    }

                    else if (data[i] != ",") {
                        v[j] += plus ? vars_i[data[i]] : -1 * vars_i[data[i]];
                        j++;
                    }
                    
                    i++;

                }
            }

        }
    }
}
