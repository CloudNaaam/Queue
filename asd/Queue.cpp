#include "Queue.h"
#include "SortAlgorithm.h"

const int BUCKET = 10, DIGIT = 3;

void Error(string s) { cerr << s;exit(-1); }
void Queue::Insert(Data d) {
	if (IsFull()) Error("Queue is full");
	rear = (rear + 1) % QUEUE_SIZE;
	data[rear] = d; length++;
}
Data Queue::Delete() {
	if (IsEmpty()) Error("Queue is empty");
	Data out = data[front];
	front = (front + 1) % QUEUE_SIZE;
	return out;
}
Data Queue::Peek() {
	if (IsEmpty()) Error("Queue is empty");
	return data[front];
}
void Queue::PrintQueue() {
	cout << "Queue: ";
	for (int i = 0; i < length;i++) {
		cout << data[(front + i) % QUEUE_SIZE];
		cout << " ";
	}
	cout << endl;
}
void Queue::PrintBuffer() {
	cout << "Buffer: front = " << front;
	cout << "; rear = " << rear << ";";
	for (int i = 0;i < QUEUE_SIZE;i++) {
		if ((front <= i && i <= front + length - 1) || (rear - length + 1 <= i && i <= rear))
			cout << data[i] << " ";
		else
			cout << "--";
	}
	cout << endl;
}

	class RadixSort :public SortAlgorithm {
	public:
		void Sort(int a[], int length) {
			Queue q[BUCKET]; // Queue q 선언
			for (int factor = 1, d = 0;d < DIGIT;d++) { // DIGIT는 자릿수를 의미
				for (int i = 0;i<length;i++) {
					int bucket = (a[i] / factor) % BUCKET; // 
					q[bucket].Insert(a[i]);
				} // Queue에 하나씩 삽입
				for (int j = 0, b = 0;b < BUCKET;b++) {
					while (q[b].IsEmpty() == false) {
						a[j++] = q[b].Delete();
					} // Queue로부터 하나씩 삭제
				}
				factor *= BUCKET; // 1, 10, 100
				PrintArray(a,length);
			}
		}
	};

	int main()
	{
		const int SIZE = 10;
		int a[] = { 234,341,568,3,692,987,736,58,820,419 };
		RadixSort s;
		s.PrintArray(a, SIZE);
		s.Sort(a, SIZE);
		return 0;
	}
