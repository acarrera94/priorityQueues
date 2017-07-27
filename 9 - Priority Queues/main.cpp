#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "PriorityQueue.h"
#include "TestCase.h"

void TestCtorBasic()
{
	TestCase tc("Call the ctor, and test the Count() method.");

	try
	{
		PriorityQueue<int> queue;

		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestDequeueEmpty()
{
	TestCase tc("Calling dequeue on an empty queue throws an exception.");

	try
	{
		PriorityQueue<int> queue;

		try
		{
			tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
			int x = queue.Dequeue();
			tc.LogResult(RESULT_FAILED, "Calling dequeue on an empty list did not throw an exception!");
		}
		catch (exception ex)
		{
			tc.LogResult(RESULT_PASSED, "Caught the exception.");
		}
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestEnqueueOneItem()
{
	TestCase tc("Enqueue one item.");

	try
	{
		PriorityQueue<double> queue;
		queue.Enqueue(3.14159);

		tc.AssertEquals(1, queue.Count(), "Make sure count is 1");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestOneItem()
{
	TestCase tc("Test one item.");

	try
	{
		PriorityQueue<char> queue;
		queue.Enqueue('G');
		tc.AssertEquals(1, queue.Count(), "Make sure count is 1");

		char ch = queue.Dequeue();
		tc.AssertEquals('G', ch, "Got a 'G' character.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestThreeItemsInOrder()
{
	TestCase tc("Three items, in order.");

	try
	{
		PriorityQueue<char> queue;
		queue.Enqueue('C');
		queue.Enqueue('B');
		queue.Enqueue('A');
		tc.AssertEquals(3, queue.Count(), "Make sure count is 3");

		tc.AssertEquals('C', queue.Dequeue(), "Got a 'C' character.");
		tc.AssertEquals('B', queue.Dequeue(), "Got a 'B' character.");
		tc.AssertEquals('A', queue.Dequeue(), "Got a 'A' character.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestThreeItemsReverseOrder()
{
	TestCase tc("Three items, reverse order.");

	try
	{
		PriorityQueue<char> queue;
		queue.Enqueue('A');
		queue.Enqueue('B');
		queue.Enqueue('C');
		tc.AssertEquals(3, queue.Count(), "Make sure count is 3");

		tc.AssertEquals('C', queue.Dequeue(), "Got a 'C' character.");
		tc.AssertEquals('B', queue.Dequeue(), "Got a 'B' character.");
		tc.AssertEquals('A', queue.Dequeue(), "Got a 'A' character.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestSevenItemsInOrder()
{
	TestCase tc("Seven items, in order.");

	try
	{
		PriorityQueue<int> queue;
		queue.Enqueue(70);
		queue.Enqueue(60);
		queue.Enqueue(50);
		queue.Enqueue(40);
		queue.Enqueue(30);
		queue.Enqueue(20);
		queue.Enqueue(10);
		tc.AssertEquals(7, queue.Count(), "Make sure count is 7");

		tc.AssertEquals(70, queue.Dequeue(), "Got a 70.");
		tc.AssertEquals(60, queue.Dequeue(), "Got a 60.");
		tc.AssertEquals(50, queue.Dequeue(), "Got a 50.");
		tc.AssertEquals(40, queue.Dequeue(), "Got a 40.");
		tc.AssertEquals(30, queue.Dequeue(), "Got a 30.");
		tc.AssertEquals(20, queue.Dequeue(), "Got a 20.");
		tc.AssertEquals(10, queue.Dequeue(), "Got a 10.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestSevenItemsReverseOrder()
{
	TestCase tc("Seven items, reverse order.");

	try
	{
		PriorityQueue<int> queue;
		queue.Enqueue(10);
		queue.Enqueue(20);
		queue.Enqueue(30);
		queue.Enqueue(40);
		queue.Enqueue(50);
		queue.Enqueue(60);
		queue.Enqueue(70);
		tc.AssertEquals(7, queue.Count(), "Make sure count is 7");

		tc.AssertEquals(70, queue.Dequeue(), "Got a 70.");
		tc.AssertEquals(60, queue.Dequeue(), "Got a 60.");
		tc.AssertEquals(50, queue.Dequeue(), "Got a 50.");
		tc.AssertEquals(40, queue.Dequeue(), "Got a 40.");
		tc.AssertEquals(30, queue.Dequeue(), "Got a 30.");
		tc.AssertEquals(20, queue.Dequeue(), "Got a 20.");
		tc.AssertEquals(10, queue.Dequeue(), "Got a 10.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestFullQueueRandomized()
{
	TestCase tc("Fill the queue with random data.");

	try
	{
		PriorityQueue<short> queue;
		queue.Enqueue(6);
		queue.Enqueue(7);
		queue.Enqueue(11);
		queue.Enqueue(2);
		queue.Enqueue(9);
		queue.Enqueue(10);
		queue.Enqueue(12);
		queue.Enqueue(3);
		queue.Enqueue(15);
		queue.Enqueue(13);
		queue.Enqueue(5);
		queue.Enqueue(16);
		queue.Enqueue(8);
		queue.Enqueue(14);
		queue.Enqueue(1);
		queue.Enqueue(4);
		tc.AssertEquals(16, queue.Count(), "Make sure count is 16");

		tc.AssertEquals(16, queue.Dequeue(), "Got a 16.");
		tc.AssertEquals(15, queue.Dequeue(), "Got a 15.");
		tc.AssertEquals(14, queue.Dequeue(), "Got a 14.");
		tc.AssertEquals(13, queue.Dequeue(), "Got a 13.");
		tc.AssertEquals(12, queue.Dequeue(), "Got a 12.");
		tc.AssertEquals(11, queue.Dequeue(), "Got a 11.");
		tc.AssertEquals(10, queue.Dequeue(), "Got a 10.");
		tc.AssertEquals(9, queue.Dequeue(), "Got a 9.");
		tc.AssertEquals(8, queue.Dequeue(), "Got a 8.");
		tc.AssertEquals(7, queue.Dequeue(), "Got a 7.");
		tc.AssertEquals(6, queue.Dequeue(), "Got a 6.");
		tc.AssertEquals(5, queue.Dequeue(), "Got a 5.");
		tc.AssertEquals(4, queue.Dequeue(), "Got a 4.");
		tc.AssertEquals(3, queue.Dequeue(), "Got a 3.");
		tc.AssertEquals(2, queue.Dequeue(), "Got a 2.");
		tc.AssertEquals(1, queue.Dequeue(), "Got a 1.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestFullQueueManyDuplicates()
{
	TestCase tc("Fill the queue with random data containing duplicates.");

	try
	{
		PriorityQueue<short> queue;
		queue.Enqueue(2);
		queue.Enqueue(3);
		queue.Enqueue(1);
		queue.Enqueue(2);
		queue.Enqueue(1);
		queue.Enqueue(4);
		queue.Enqueue(2);
		queue.Enqueue(3);
		queue.Enqueue(1);
		queue.Enqueue(3);
		queue.Enqueue(3);
		queue.Enqueue(2);
		queue.Enqueue(4);
		queue.Enqueue(4);
		queue.Enqueue(1);
		queue.Enqueue(4);
		tc.AssertEquals(16, queue.Count(), "Make sure count is 16");

		tc.AssertEquals(4, queue.Dequeue(), "Got a 4.");
		tc.AssertEquals(4, queue.Dequeue(), "Got a 4.");
		tc.AssertEquals(4, queue.Dequeue(), "Got a 4.");
		tc.AssertEquals(4, queue.Dequeue(), "Got a 4.");
		tc.AssertEquals(3, queue.Dequeue(), "Got a 3.");
		tc.AssertEquals(3, queue.Dequeue(), "Got a 3.");
		tc.AssertEquals(3, queue.Dequeue(), "Got a 3.");
		tc.AssertEquals(3, queue.Dequeue(), "Got a 3.");
		tc.AssertEquals(2, queue.Dequeue(), "Got a 2.");
		tc.AssertEquals(2, queue.Dequeue(), "Got a 2.");
		tc.AssertEquals(2, queue.Dequeue(), "Got a 2.");
		tc.AssertEquals(2, queue.Dequeue(), "Got a 2.");
		tc.AssertEquals(1, queue.Dequeue(), "Got a 1.");
		tc.AssertEquals(1, queue.Dequeue(), "Got a 1.");
		tc.AssertEquals(1, queue.Dequeue(), "Got a 1.");
		tc.AssertEquals(1, queue.Dequeue(), "Got a 1.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestFullQueueOverflow()
{
	TestCase tc("Queue throws an exception when full.");

	try
	{
		PriorityQueue<short> queue;
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		queue.Enqueue(1);
		tc.AssertEquals(16, queue.Count(), "Make sure count is 16");

		try
		{
			queue.Enqueue(0);
			tc.LogResult(RESULT_FAILED, "Enqueuing a 17th item should have thrown an exception.");
		}
		catch (exception ex)
		{
			tc.LogResult(RESULT_PASSED, "Caught an exception on the 17th item.");
		}
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


void TestTheClearMethod()
{
	TestCase tc("Fill the queue with random data.");

	try
	{
		PriorityQueue<float> queue;
		queue.Enqueue(100);
		queue.Enqueue(200);
		queue.Enqueue(300);
		tc.LogResult(RESULT_PASSED, "Enqueued 3 items.");
		tc.AssertEquals(3, queue.Count(), "Make sure count is 3");

		queue.Clear();
		tc.LogResult(RESULT_PASSED, "Queue has been cleared.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is 0");

		queue.Enqueue(6);
		queue.Enqueue(7);
		queue.Enqueue(11);
		queue.Enqueue(2);
		queue.Enqueue(9);
		queue.Enqueue(10);
		queue.Enqueue(12);
		queue.Enqueue(3);
		queue.Enqueue(15);
		queue.Enqueue(13);
		queue.Enqueue(5);
		queue.Enqueue(16);
		queue.Enqueue(8);
		queue.Enqueue(14);
		queue.Enqueue(1);
		queue.Enqueue(4);
		tc.LogResult(RESULT_PASSED, "Enqueued 16 items.");
		tc.AssertEquals(16, queue.Count(), "Make sure count is 16");

		tc.AssertEquals(16, queue.Dequeue(), "Got a 16.");
		tc.AssertEquals(15, queue.Dequeue(), "Got a 15.");
		tc.AssertEquals(14, queue.Dequeue(), "Got a 14.");
		tc.AssertEquals(13, queue.Dequeue(), "Got a 13.");
		tc.AssertEquals(12, queue.Dequeue(), "Got a 12.");
		tc.AssertEquals(11, queue.Dequeue(), "Got a 11.");
		tc.AssertEquals(10, queue.Dequeue(), "Got a 10.");
		tc.AssertEquals(9, queue.Dequeue(), "Got a 9.");
		tc.AssertEquals(8, queue.Dequeue(), "Got a 8.");
		tc.AssertEquals(7, queue.Dequeue(), "Got a 7.");
		tc.AssertEquals(6, queue.Dequeue(), "Got a 6.");
		tc.AssertEquals(5, queue.Dequeue(), "Got a 5.");
		tc.AssertEquals(4, queue.Dequeue(), "Got a 4.");
		tc.AssertEquals(3, queue.Dequeue(), "Got a 3.");
		tc.AssertEquals(2, queue.Dequeue(), "Got a 2.");
		tc.AssertEquals(1, queue.Dequeue(), "Got a 1.");
		tc.AssertEquals(0, queue.Count(), "Make sure count is zero");
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}
}


int main()
{
	TestCtorBasic();
	TestDequeueEmpty();
	TestEnqueueOneItem();
	TestOneItem();
	TestThreeItemsInOrder();
	TestThreeItemsReverseOrder();
	TestSevenItemsInOrder();
	TestSevenItemsReverseOrder();
	TestFullQueueRandomized();
	TestFullQueueManyDuplicates();
	TestFullQueueOverflow();
	TestTheClearMethod();

	TestCase::PrintSummary();
    
    return 0;
}
