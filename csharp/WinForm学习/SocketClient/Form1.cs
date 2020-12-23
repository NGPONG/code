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

namespace SocketClient
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        Socket socketClient;
        private void button1_Click(object sender, EventArgs e)
        {
            socketClient = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPAddress ip = IPAddress.Parse(txtIPAddress.Text);
            IPEndPoint port = new IPEndPoint(ip, int.Parse(txtPoint.Text));
            socketClient.Connect(port);
            txtSocketMsg.AppendText("连接服务端成功！\n");

            Thread th1 = new Thread(ReceiveServerMsg);
            th1.IsBackground = true;
            th1.Start(socketClient);
        }


        public void ReceiveServerMsg(object o) 
        {
            Socket socketClient = o as Socket;
            while (true)
            {
                try
                {
                    byte[] byts = new byte[1024 * 1024 * 5];
                    int r = socketClient.Receive(byts);

                    // 如果Server通过Close()和Dispose()关闭了当前Socket的连接通道，Server会发送一个0字节包到Client以确认状态，区别于Disconnect()，该包只会发送一次
                    if (r == 0)
                    {

                    }

                    if (byts[0] == 0)
                    {
                        txtSocketMsg.AppendText(socketClient.RemoteEndPoint.ToString() + "  " + DateTime.Now.ToString() + "\r\n" + Encoding.Default.GetString(byts, 1, r - 1) + "\n");
                    }
                    else if (byts[0] == 1)
                    {
                        saveFileDialog1.Title = "请选择要保存的路径";
                        saveFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
                        saveFileDialog1.Filter = "所有文件|*.*|文本文件|*.txt|图片|*.jpg|音乐|*.mp3";
                        switch (byts[1])
                        {
                            case 0:
                                saveFileDialog1.FileName = "*.txt";
                                break;
                            case 1:
                                saveFileDialog1.FileName = "*.jpg";
                                break;
                            case 2:
                                saveFileDialog1.FileName = "*.mp3";
                                break;
                            case 3:
                                saveFileDialog1.FileName = "*.*";
                                break;
                        }
                        saveFileDialog1.ShowDialog(this);

                        //如果用户并没有选择保存路径时
                        try
                        {
                            using (FileStream fsWrite = new FileStream(saveFileDialog1.FileName, FileMode.Create, FileAccess.Write))
                            {
                                fsWrite.Write(byts, 2, r - 2);
                                txtSocketMsg.AppendText("保存文件成功！文件路径为：" + saveFileDialog1.FileName);
                            }
                        }
                        catch
                        {

                        }
                    }
                    else if (byts[0] == 2)
                    {
                        formMethod();
                    }

                }
                catch (Exception e)
                {
                    string str = e.Message;
                }
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            socketClient.Send(Encoding.Default.GetBytes(txtClientSend.Text));
            txtSocketMsg.AppendText(socketClient.LocalEndPoint.ToString() + "  " + DateTime.Now.ToString() + "\r\n" + txtClientSend.Text + "\n");
            txtClientSend.Focus();
            txtClientSend.Clear();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
        }

        public void formMethod() 
        {
            int x = this.Location.X;
            int y = this.Location.Y;
            for (int i = 0; i < 200; i++)
            {
                Point p1 = new Point(x + 100, y + 100);
                Point p2 = new Point(x - 100, y - 100);
                this.Location = p1;
                this.Location = p2;
            }
        }
        private void button3_Click(object sender, EventArgs e)
        {
            // 关闭当前Socket的连接并阻塞Client的主线程继续调用，并且不断的发送一个0字节的包到服务器上，直至Server关闭了对该Sokcet的连接通道，才恢复主线程的调用
            //socketClient.Disconnect(true);
            socketClient.Shutdown(SocketShutdown.Send);
            string str = "123";
        }
    }
}
