using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Socket_Server
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //创建监听Socket对象，负责监听服务端软件的IP地址与端口号，指定了该Socket监听该软件的IP地址类型，与协议类型
            Socket socketWatch = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            //为该服务端的这个软件设置端口数值（创建端口的对象）
            IPEndPoint point = new IPEndPoint(IPAddress.Any, int.Parse(txtPoint.Text));
            //把服务器的这个软件的端口地址与监听用的Socket进行绑定
            socketWatch.Bind(point);

            ShowMsg("正在监听中…");

            //socketWatch设置为监听状态，并设置某个时间段的最大监听数
            socketWatch.Listen(10);

            //监听成功后的socketWatch创建新的Socket负责与客户端进行连接
            //Socket socketSend = socketWatch.Accept();
            Thread th = new Thread(ListenSocket);
            th.IsBackground = true;
            th.Start(socketWatch);
        }
        /// <summary>
        /// 创建新的线程，接受服务端监听Socket的连接状态，成功连接则创建一个跟客户端交互的Socket
        /// </summary>
        /// <param name="sk">监听的Socket</param>
        public void ListenSocket(object sk)
        {
            Socket socketWatch = (Socket)sk;
            while (true) 
            {
                Socket socketSend = socketWatch.Accept();
                ShowMsg(socketSend.RemoteEndPoint.ToString() + "连接成功！");
            }
        }
        public void ShowMsg(string str) 
        {
        txtShowConnect.AppendText(str+"\n");
        }
        private void button2_Click(object sender, EventArgs e)
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
        }
    }
}
