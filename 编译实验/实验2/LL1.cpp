#include<bits/stdc++.h>
using namespace std;

struct Grammar 
{
	char production_left;
	string production_right;
};


class LL1
{
private:
	int numberOFproduction=0;
	vector<char> nonempty_terminal_symbol; //��ȥ$���ս��
	vector<char> terminal_symbol;//�ս������ 
	vector<char> non_terminal_symbol;//���ս������ 
	Grammar grammar[105]; //�ķ�
	set<char> first[105];//first��
	set<char> follow[105];//follow��
	vector<char> analyze_stack; //����ջ
	vector<char> residue_inputstring;//ʣ�����봮
	int table[105][105];//Ԥ���
public:
	bool isNon_terminal_symbol(char c);//�ж��Ƿ��Ƿ��ս����Ĭ�ϴ�д��ĸΪ���ս�� 
	int get_VTindex(char c);//���c���ս�������е��±�
	int get_VNindex(char c);//���c�ڷ��ս�������е��±�
	void getFirst(char c); //�õ�first����
	void getFollow(char c);//�õ�follow����
	void input(); //���룬���Ҽ���first��follow
	void display(); //��ʾfirst��follow�Լ�Ԥ������� 
	void getTable(); //�õ�Ԥ�������
	void analyze(string symbolstring); //����������ַ��� 
};

bool LL1::isNon_terminal_symbol(char c)//�ж��Ƿ����ս����Ĭ��Сд��ĸΪ�ս�������ս������false 
{
	if (c >= 'A' && c <= 'Z')//��д��ĸ�Ƿ��ս�� 
		return true;
	else
	return false;
}

int LL1::get_VTindex(char c)//���c���ս�������е��±꣬����û�з���-1 
{
	for (int i = 0; i < non_terminal_symbol.size(); i++)
	{
		if (c == non_terminal_symbol[i])
			return i;
	}
	return -1;
}

int LL1::get_VNindex(char c)//���c�ڷ��ս�������е��±꣬����û�з���-1 
{
	for (int i = 0; i < terminal_symbol.size(); i++)
	{
		if (c == terminal_symbol[i])
			return i;
	}
	return -1;
}

void LL1::getFirst(char c)//����ս����first�� 
{
	int empty = 0;//��¼�Ҳ����ս���Ƿ����Ƴ��� 
	int flag = 0;//��¼���ս���Ƿ����Ƴ�$ 
	for (int i = 0; i < numberOFproduction; i++)
	{
		if (grammar[i].production_left == c)
		{
			if (!isNon_terminal_symbol(grammar[i].production_right[0]))//�����ս����ֱ�Ӽ���first
			{
				first[get_VTindex(c)].insert(grammar[i].production_right[0]);
			}
			else
			{
				for (int j = 0; j < grammar[i].production_right.length(); j++)
				{
					if (!isNon_terminal_symbol(grammar[i].production_right[j]))
					{
						first[get_VTindex(c)].insert(grammar[i].production_right[j]);
						break;
					}
					getFirst(grammar[i].production_right[j]);
					set<char>::iterator it;
					for (it = first[get_VTindex(grammar[i].production_right[j])].begin(); it != first[get_VTindex(grammar[i].production_right[j])].end(); it++)
					{
						if (*it == '$')
							flag = 1;
						else
							first[get_VTindex(c)].insert(*it);//��$�ͼ���FIRST
					}
					if (flag == 0)
						break;
					else
					{
						empty ++;
						flag = 0;
					}
				}
				if (empty == grammar[i].production_right.length())//����ʽ�Ҳ����Ƴ�$ 
					first[get_VTindex(c)].insert('$');
			}
		}
	}

}

void LL1::getFollow(char c)//����ս����follow�����Ľ��汾�� 
{
	for (int i = 0; i < numberOFproduction; i++)
	{
		int index = -1;
		int len = grammar[i].production_right.length();
		for (int j = 0; j < len; j++)
		{
			if (grammar[i].production_right[j] == c)
			{
				index = j;
				break;
			}
		}
		if (index != -1 && index < len - 1)
		{
			char next = grammar[i].production_right[index + 1];
			if (!isNon_terminal_symbol(next))//�����������ս����ֱ�Ӽ��� 
			{
				follow[get_VTindex(c)].insert(next);
			}
			else//�Ѻ���ķ��ս����first������$���� 
			{
				int flag = 0;
				set<char>::iterator it;
				for (it = first[get_VTindex(next)].begin(); it != first[get_VTindex(next)].end(); it++)
				{
					if (*it == '$')
						flag = 1;
					else
						follow[get_VTindex(c)].insert(*it);
				}
				if (flag==1 && grammar[i].production_left != c)
				{
					getFollow(grammar[i].production_left);
					set<char>::iterator it;
					char tmp = grammar[i].production_left;
					for (it = follow[get_VTindex(tmp)].begin(); it != follow[get_VTindex(tmp)].end(); it++)
						follow[get_VTindex(c)].insert(*it);
				}
			}
		}

		else if (index != -1 && index == len - 1 && c != grammar[i].production_left)
		{
			getFollow(grammar[i].production_left);
			set<char>::iterator it;
			char temp = grammar[i].production_left;
			for (it = follow[get_VTindex(temp)].begin(); it != follow[get_VTindex(temp)].end(); it++)
				follow[get_VTindex(c)].insert(*it);
		}

	}
}

void LL1::input()
{
	string production;
	cout << "*****************���������ʽ�ĸ���**********************" << endl;
	cin >> numberOFproduction;
	cout << "***********���������ʽ���ղ���ʽ��$���棩***************" << endl;
	for (int index = 0; index < numberOFproduction; index++)
	{
		cin >> production;
		grammar[index].production_left = production[0];
		for (int i = 3; i < production.length(); i++)
			grammar[index].production_right += production[i];
		for (int i = 0; i < production.length(); i++)
		{
			if (production[i] != '-' && production[i] != '>')
			{
				if (isNon_terminal_symbol(production[i]))
				{
					int flag = 0;
					for (int j = 0; j < non_terminal_symbol.size(); j++)
					{
						if (non_terminal_symbol[j] == production[i])
						{
							flag = 1;
							break;
						}
					}
					if (!flag)
						non_terminal_symbol.push_back(production[i]);

				}
				else
				{
					int flag = 0;
					for (int j = 0; j < terminal_symbol.size(); j++)
					{
						if (terminal_symbol[j] == production[i])
						{
							flag = 1;
							break;
						}
					}
					if (!flag)
						terminal_symbol.push_back(production[i]);
				}
			}
		}

	}
	terminal_symbol.push_back('#');
	for (int i = 0; i < non_terminal_symbol.size(); i++)
	{
		getFirst(non_terminal_symbol[i]);
	}

	for (int i = 0; i < non_terminal_symbol.size(); i++)
	{
		if (i == 0)
			follow[0].insert('#');
		getFollow(non_terminal_symbol[i]);
	}

	for (int i = 0; i < terminal_symbol.size(); i++)
	{
		if (terminal_symbol[i] != '$')
			nonempty_terminal_symbol.push_back(terminal_symbol[i]);
	}
}

void LL1::display()
{
	//������з��ս����first�� 
	cout << "******************FIRST����***********************" << endl;
	for (int i = 0; i < non_terminal_symbol.size(); i++)
	{
		cout << non_terminal_symbol[i] << ": ";
		set<char>::iterator it;
		for (it = first[i].begin(); it != first[i].end(); it++)
			cout << *it << "  ";
		cout << endl;
	}
//������з��ս����follow�� 
	cout << "******************FOLLOW����*********************" << endl;
	for (int i = 0; i < non_terminal_symbol.size(); i++)
	{
		cout << non_terminal_symbol[i] << ": ";
		set<char>::iterator it;
		for (it = follow[i].begin(); it != follow[i].end(); it++)
			cout << *it << "  ";
		cout << endl;
	}
	cout << "******************Ԥ�������********************" << endl;
	//���Ԥ�������table
	for (int i = 0; i < terminal_symbol.size(); i++)
	{
		cout << setw(10) << terminal_symbol[i];
	}
		cout << endl;
	for (int i = 0; i < non_terminal_symbol.size(); i++)
	{
		cout << non_terminal_symbol[i] << ": ";
		for (int j = 0; j < terminal_symbol.size(); j++)
		{
			if (table[i][j] == -1)
				cout << setw(10) << "Error";
			else
				cout << setw(10) << grammar[table[i][j]].production_right;
		}
			cout << endl;
	}
	
}


void LL1::getTable()
{
	memset(table,-1,sizeof(table));
	for (int i = 0; i < numberOFproduction; i++)
	{
		char temp = grammar[i].production_right[0];
		if (!isNon_terminal_symbol(temp))//����ʽ�ұ���һ���ս�� 
		{
			if (temp != '$')
				table[get_VTindex(grammar[i].production_left)][get_VNindex(temp)] = i;
			if (temp == '$')
			{
				set<char>::iterator  it;
				for (it = follow[get_VTindex(grammar[i].production_left)].begin(); it != follow[get_VTindex(grammar[i].production_left)].end(); it++)
				{
					table[get_VTindex(grammar[i].production_left)][get_VNindex(*it)] = i;
				}
			}
		}
		else//����ʽ�ұ���һ�����ս�� 
		{
			set<char>::iterator ti;
			for (ti = first[get_VTindex(temp)].begin(); ti != first[get_VTindex(temp)].end(); ti++)
			{
				table[get_VTindex(grammar[i].production_left)][get_VNindex(*ti)] = i;
			}
			if (first[get_VTindex(temp)].count('$') != 0)
			{
				set<char>::iterator  it;
				for (it = follow[get_VTindex(grammar[i].production_left)].begin(); it != follow[get_VTindex(grammar[i].production_left)].end(); it++)
				{
					table[get_VTindex(grammar[i].production_left)][get_VNindex(*it)] = i;
				}
			}
		}
	}
}

void LL1::analyze(string symbolstring)
{
	cout<<"*********************�����ַ���**********************************"<<endl; 
	cout << setw(15) << "����ջ" << setw(15) << "ʣ�����봮" << setw(15) << "����ʽ" << endl;
	for (int i = symbolstring.length() - 1; i >= 0; i--)
		residue_inputstring.push_back(symbolstring[i]);
	analyze_stack.push_back('#');
	analyze_stack.push_back(non_terminal_symbol[0]);
	while (residue_inputstring.size() > 0)
	{
		string outs = "";
		for (int i = 0; i < analyze_stack.size(); i++)
			outs += analyze_stack[i];
		cout << setw(15) << outs;
		outs = "";
		for (int i = residue_inputstring.size() - 1; i >= 0; i--)
			outs += residue_inputstring[i];
		cout << setw(15) << outs;
		char c1 = analyze_stack[analyze_stack.size() - 1];
		char c2 = residue_inputstring[residue_inputstring.size() - 1];
		if (c1 == c2 && c1 == '#')
		{
			cout << setw(15) << "Accepted!" << endl;
			return;
		}
		if (c1 == c2)
		{
			analyze_stack.pop_back();
			residue_inputstring.pop_back();
			cout << setw(15) << c1 << "ƥ��" << endl;
		}
		else if (table[get_VTindex(c1)][get_VNindex(c2)] != -1)
		{
			int index= table[get_VTindex(c1)][get_VNindex(c2)];
			analyze_stack.pop_back();
			if (grammar[index].production_right != "$")
			{
				for (int i = grammar[index].production_right.length() - 1; i >= 0; i--)
					analyze_stack.push_back(grammar[index].production_right[i]);
			}
			cout << setw(15) << grammar[index].production_right << endl;
		}
		else
		{
			cout << setw(15) << "Error!" << endl;
			return;
		}
	}
}

int main()
{
	LL1 ll1;
    ll1.input();	
	ll1.getTable();
	ll1.display();
	string symbolstring;
	cout << "�������ַ�����" << endl;
	cin >> symbolstring;
	ll1.analyze(symbolstring);
	return 0;
}
