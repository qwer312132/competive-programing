//stringstream
string in, out, tmp;
cin >> in;
cin.ignore();
stringstream ss(in);
while(getline(ss, tmp, {char})) out += tmp;
//while(ss >> tmp) out += tmp;
