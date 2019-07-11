using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SocketServer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //创建服务端负责监听的Socket的对象，规定了该Socket所绑定的IP地址类型与协议类型
            Socket socketListen = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            //创建监听Socket监听的IP地址对象
            IPAddress ip = IPAddress.Parse(txtIPAddress.Text); //IPAddress ip = IPAddress.Any;
            //创建监听Socket监听的端口对象
            IPEndPoint port = new IPEndPoint(ip, Convert.ToInt32(txtPoint.Text));
            //绑定监听Socket监听的IP和端口对象
            socketListen.Bind(port);
            //设置该Socket在该时间点内最大连接数
            socketListen.Listen(10);

            showMsg("开始监听…");

            //开启线程1 来让服务端的监听Socket一直处于监听IP地址和端口号的状态
            //如果不开新线程，利用主线程来接收客户端的连接
            //则主线程一直在做这件事，程序就会假卡死
            Thread th1= new Thread(SocketListenMsg);
            th1.IsBackground = true;
            th1.Start(socketListen);
        }
        List<Socket> list = new List<Socket>();
        public void SocketListenMsg(object o) 
        {
            Socket socketListen = o as Socket;
            while (true) 
            {
                //等待客户端的连接
                //如果连接成功，则创建一个交流的Socket负责跟客户端通信
                //如果没有连接则一直再Accept方法中等待新的连接
                Socket socketCommunicate =  socketListen.Accept();
                list.Add(socketCommunicate);
                comboBox1.Items.Add(socketCommunicate.RemoteEndPoint.ToString());
                comboBox1.SelectedIndex = 0;
                showMsg(socketCommunicate.RemoteEndPoint.ToString() + "  连接成功！");
                //开启一个新线程负责接收客户端发来的消息
                //如果不开新线程做这件事
                //当服务端负责交流的Socket接收到客户端发来的数据并追加到TEXT控件的文本内容的时候，程序又会继续循环，在Accept()这个方法等待第二个用户的连接
                //不会再继续接收客户端的第二条信息
                Thread thNew = new Thread(ReceiveClientMsg);
                thNew.IsBackground = true;
                thNew.Start(socketCommunicate);
            }
        }
        /// <summary>
        /// 接收客户端发来的信息
        /// </summary>
        /// <param name="o"></param>
        public void ReceiveClientMsg(object o) 
        {
            Socket socketCommunicate = o as Socket;
            while (true)
            {
                try
                {
                    byte[] byts = new byte[1024 * 1024 * 5];
                    int r = socketCommunicate.Receive(byts);

                    // 如果Client调用了Sokct的ShutDown或Disconnected去尝试关闭套接字的连接，则会不断地发送0字节的数据至服务端已确认Client已经关闭连接了，Server也要随之关闭对Client的TCP连接通道
                    if (r == 0)
                    {
                        // 通过Poll函数再次确认Sokct的连接状态，因为0字节的数据发送可能不是Client需要关闭才发送的
                        if (socketCommunicate.Poll(1, SelectMode.SelectRead))
                        {
                            socketCommunicate.Shutdown(SocketShutdown.Both);
                            // 关闭对Client的TCP连接通道
                            socketCommunicate.Close();
                            //socketCommunicate.Dispose();
                            break;
                        }
                    }

                    txtSockerListenMsg.AppendText(socketCommunicate.RemoteEndPoint.ToString() + "  " + DateTime.Now.ToString() + "\r\n" + Encoding.Default.GetString(byts, 0, r) + "\n");
                }
                catch(Exception e)
                {
                    string str = e.Message;
                }
            }
        }

        public void showMsg(string str) 
        {
            txtSockerListenMsg.AppendText(str + "\n");
        }

        /// <summary>
        /// 程序开始的时候取消对跨线程的访问
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
        }
        /// <summary>
        /// 给客户端发送信息
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button2_Click(object sender, EventArgs e)
        {
            //给客户端发送数据
            byte[] byts = Encoding.Default.GetBytes(textBox1.Text);
            List<byte> listbyts = byts.ToList();
            //自己写一个协议，0代表发送的是文本
            listbyts.Insert(0, 0);
            list[comboBox1.SelectedIndex].Send(listbyts.ToArray());
            txtSockerListenMsg.AppendText(list[comboBox1.SelectedIndex].LocalEndPoint.ToString() + "  " + DateTime.Now.ToString() + "\r\n" + textBox1.Text + "\n");
            textBox1.Clear();
            textBox1.Focus();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //初始化打开对话框
            openFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            openFileDialog1.Title = "选择发送的文件";
            openFileDialog1.Filter = "所有文件|*.*|文本文件|*.txt|图片|*.jpg|音乐|*.mp3";
            openFileDialog1.ShowDialog();
        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            textBox2.Text = openFileDialog1.FileName;
        }
        /// <summary>
        /// 给客户端发送文件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button4_Click(object sender, EventArgs e)
        {
            //通过文件流传输字节数据
            using (FileStream fsRead = new FileStream(openFileDialog1.FileName, FileMode.Open, FileAccess.Read)) 
            {
                byte[] byts = new byte[fsRead.Length];
                fsRead.Read(byts, 0, byts.Length);
                List<byte> listbyts =  byts.ToList();
                //自己写一个协议，1代表传输的是文件
                listbyts.Insert(0, 1);
                //自己写另一个协议，0代表传的是文本文件，1代表传的是jpg，2为MP3，3为未知
                if (openFileDialog1.FileName.Contains("txt")) 
                {
                    listbyts.Insert(1, 0);
                }
                else if (openFileDialog1.FileName.Contains("jpg")) 
                {
                    listbyts.Insert(1, 1);
                }
                else if (openFileDialog1.FileName.Contains("mp3"))
                {
                    listbyts.Insert(1, 2);
                }
                else 
                {
                    listbyts.Insert(1, 3);
                }
                list[comboBox1.SelectedIndex].Send(listbyts.ToArray());
                txtSockerListenMsg.AppendText("文件发送成功！");
            }
        }
        /// <summary>
        /// 给客户端发送窗口抖动
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button5_Click(object sender, EventArgs e)
        {
            //自己写一个协议，2代表发送的是震动
            byte[] byts = { 2 };
            list[comboBox1.SelectedIndex].Send(byts);
        }

    }
}
