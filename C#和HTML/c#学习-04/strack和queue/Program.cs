using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace strack和queue
{
    class Program
    {
        static void Main(string[] args)
        {

        }
    }

    #region Stack
    //// 创建一个泛型栈
    //Stack<string> myStack = new Stack<string>();

    //// 为栈顶添加一个元素
    //myStack.Push("Hello,World");

    //// 取出栈顶的元素，不进行删除，如果该队列首部没有数据，则抛出【InvalidOperationException】的异常
    //string strPeek = myStack.Peek();

    //// 取出栈顶的元素，并将该元素从队列中删除，如果该队列首部没有数据，则抛出【InvalidOperationException】的异常
    //string strPop = myStack.Pop();

    //// 获取栈的长度
    //int stack_Count = myStack.Count; 
    #endregion

    #region Queue
    //// 创建一个泛型队列
    //Queue<string> myQueue = new Queue<string>();

    //// 为队列的添加一个元素
    //myQueue.Enqueue("Hello,World");

    //// 取出队列中首部的元素，不进行删除，如果该队列首部没有数据，则抛出【InvalidOperationException】的异常
    //string strPeek = myQueue.Peek();

    //// 取出队列中首部的元素，并将该元素从队列中删除，如果该队列首部没有数据，则抛出【InvalidOperationException】的异常
    //string strDequeue = myQueue.Dequeue();

    //// 获取队列的长度
    //int count = myQueue.Count; 
    #endregion

    public class Person
    {
        public string Name { get; set; }
    }
}
