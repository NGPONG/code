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

namespace 客户端
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Socket socket;
        private void button1_Click(object sender, EventArgs e)
        {
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            //服务端的IP地址
            IPAddress ip = IPAddress.Parse(txtIPAddress.Text);
            //服务端的端口号
            IPEndPoint port = new IPEndPoint(ip, int.Parse(txtPort.Text));
            //连接服务端的IP地址和端口号
            socket.Connect(port);

            txtGetMsg.AppendText("连接成功！"+"\n");

            Thread th1 = new Thread(GetMsg);
            th1.IsBackground = true;
            th1.Start();
        }
        public void GetMsg() 
        {
            while (true)
            {
                byte[] byts = new byte[1024*1024*5];
                int r = socket.Receive(byts);
                switch (byts[0]) 
                {
                    case 0:
                        txtGetMsg.AppendText(socket.RemoteEndPoint.ToString() + "  " + Encoding.Default.GetString(byts, 1, r-1) + "\n");
                        break;
                    case 1:
                        saveFileDialog1.ShowDialog(this);
                        using (FileStream fsWrite = new FileStream(saveFileDialog1.FileName, FileMode.Create, FileAccess.Write)) 
                        {
                            fsWrite.Write(byts, 1, r - 1);
                        }
                        txtGetMsg.AppendText("文件保存成功！路径为："+saveFileDialog1.FileName);
                        break;
                }

            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            byte[] byts = Encoding.Default.GetBytes(txtSendMsg.Text);
            socket.Send(byts);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
            saveFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            saveFileDialog1.Title = "请选择要保存的路径";
            saveFileDialog1.Filter = "所有文件|*.*|文本文件|*.txt|图片|*.jpg";
        }


    }
}
