using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 线程安全的集合
{
    class Program
    {
        static void Main(string[] args)
        {
            #region ConcurrentQueue
            //// 创建一个【线程安全】的泛型队列
            //ConcurrentQueue<string> myQueue_Safety = new ConcurrentQueue<string>();

            //// 为队列的添加一个元素
            //myQueue_Safety.Enqueue("Hello,World");

            //// 尝试取出队列中首部的元素，不进行删除，如果队列首部存在数据则返回true否则返回false
            //string strPeek;
            //bool isPeekSucess = myQueue_Safety.TryPeek(out strPeek);

            //// 尝试取出队列中首部的元素，并将该元素从队列中删除，如果队列首部存在数据则返回true否则返回false
            //string strDequeue;
            //bool isDequeueSucess = myQueue_Safety.TryDequeue(out strDequeue);

            //// 获取队列的长度
            //int count = myQueue_Safety.Count; 
            #endregion

            #region ConcurrentStack
            //// 创建一个【线程安全】的栈
            //ConcurrentStack<string> myStack_Safety = new ConcurrentStack<string>();

            //// 为栈顶添加一个元素
            //myStack_Safety.Push("Hello,World");

            //// 尝试取出栈顶的元素，不进行删除，如果栈顶存在数据则返回true否则返回false
            //string strPeek;
            //bool isPeekSucess = myStack_Safety.TryPeek(out strPeek);

            //// 尝试取出栈顶的元素，并将该元素从队列中删除，如果栈顶存在数据则返回true否则返回false
            //string strPop;
            //bool isPopSucess = myStack_Safety.TryPop(out strPop);

            //// 获取栈的长度
            //int count = myStack_Safety.Count; 
            #endregion
        }
    }
}
