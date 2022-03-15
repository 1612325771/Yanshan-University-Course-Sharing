#include <iostream>
#include<string>
#include <stack>
using namespace std;
stack <char> s;
int getPriority(char c) //��ȡ���ŵ����ȼ� 
{
    switch (c)
    {
        case '+':
        case '-':
    return 1;
        case '*':
        case '/':
    return 2;
        case '%':
    return 3;
    case'#':
    default:
        return 0;
    }
}
bool judgePriority(char c1, char c2) //�ж��������ŵ����ȼ� 
{
    if (getPriority(c1) > getPriority(c2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool deleteBracket(stack<char>& s)
{
    stack<char> t;
    while (!s.empty() && s.top() != '(')//���ջ������������
    {
        t.push(s.top());
        s.pop();
    }
    if (s.empty())//֤��û����������ƥ���������
    {
        return false;
    }
    else if (s.top() == '(')//���ƥ������������
    {
        s.pop();//����������
        while (!t.empty())//�ѣ�֮�ϵ�Ԫ��ѹ��ջ
        {
            s.push(t.top());
            t.pop();
        }
        return true;
    }
}

string translate(string prefix)
{
    string result;
    s.push('#');
    for (int i = 0; i < prefix.length(); i++)
    {
        if (prefix[i] == '#')
        {
            break;
        }
        if (isalpha(prefix[i]) || isdigit(prefix[i]))//��ǰ�ַ�Ϊ��ĸ������
        {
            result += prefix[i];
        }
        else if (prefix[i] == '(')//�����ţ���ջ
        {
            s.push(prefix[i]);
        }
        else if (prefix[i] == ')')//�����ţ�ƥ�������ţ���ȥ��
        {
            if (!deleteBracket(s))
            {
                return "error";
            }
        }
        else
        {
            if (judgePriority(prefix[i], s.top()))//����ǰ�ַ������ȼ�����ջ���ַ������ȼ�
            {
                s.push(prefix[i]);//��ջ
            }
            else
            {
                while (!judgePriority(prefix[i], s.top()) && s.top() != '#'&& s.top() != '(')
                {
                    result += s.top();
                    s.pop();
                }
                s.push(prefix[i]);
            }
        }
    }
    while (!s.empty() && s.top() != '#')
    {
        result += s.top();
        s.pop();
    }
    return result;
}

int main()
{
    string s;
    while (true)
    {
        cout << "��������Ҫת������׺���ʽ������0�˳�" << endl;
        cin >> s;
        if (s == "0")
        {
            break;
        }
        s += '#';
        string inversePolandexpression = translate(s);
        cout << "�沨�����ʽΪ"<<endl;
        cout << inversePolandexpression<<endl;
    }
}

