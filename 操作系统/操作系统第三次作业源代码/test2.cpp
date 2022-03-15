#include<iostream>
#include <mutex>
#include<queue>
#include <windows.h>
#include <thread>

using namespace std;

static const int item_total = 100; //�ܹ�Ҫ���� item_total��item

// ����ṹ��, ʹ�ö��е�������
struct Buffer 
{
   queue<int> buffer;
    int in;
    int out;
    mutex mtx; 
}buffer_res;

typedef struct Buffer Buffer;

void porduce_item(Buffer *b, int item)
{
    unique_lock<mutex> lock(b->mtx);//���û�����
    // �򻺴������item
    b->buffer.push(item);
    b->in++;
    lock.unlock();
    Sleep(200);
}

int consume_item(Buffer *b)
{
	if(b->buffer.size()>0){
    unique_lock <mutex> lock(b->mtx);
    int item=b->buffer.front();
    b->out++;
    b->buffer.pop();
    lock.unlock();
    Sleep(200);
    return item;
}
}

//����������
void producer() {
    for (int i = 1; i<= item_total;i++) {
        cout << "prodece the " << i << "^th item ..." << endl;
        porduce_item(&buffer_res, i);
    }
}

//����������
void consumer()
{
    static int cnt = 0;
    while(1) {
        int item = consume_item(&buffer_res);
        cout << "consume the " << item << "^th item" << endl;
        if (++cnt == item_total)
            break;
    }
}

//��ʼ�� buffer
void init_buffer(Buffer *b)
{
    b->in = 0;
    b->out = 0;
}

int main()
{
	clock_t startTime, endTime;
	startTime = clock();//��ʱ��ʼ
    init_buffer(&buffer_res);
    thread prodece(producer);
    thread consume(consumer);
    prodece.join();
    consume.join();
    endTime = clock();//��ʱ����
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    getchar();
}

