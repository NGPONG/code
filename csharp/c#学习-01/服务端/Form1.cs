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

namespace 服务端
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Socket socketListen = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPAddress ip = IPAddress.Any;
            IPEndPoint port = new IPEndPoint(ip, int.Parse(txtPort.Text));
            socketListen.Bind(port);
            socketListen.Listen(10);

            txtGetMsg.AppendText("开始监听…"+"\n");

            Thread th1 = new Thread(GetAccept);
            th1.IsBackground = true;
            th1.Start(socketListen);
        }
        //
        List<Socket> list = new List<Socket>();
        Socket socketCommunicate;
        //
        public void GetAccept(object o) 
        {
            Socket socketListen = (Socket)o;
            while (true) 
            {
                socketCommunicate = socketListen.Accept();
                //
                comboBox1.Items.Add(socketCommunicate.RemoteEndPoint.ToString());
                list.Add(socketCommunicate);
                //
                txtGetMsg.AppendText(socketCommunicate.RemoteEndPoint.ToString() + "  连接成功！" + "\n");
                
                Thread thNew = new Thread(GetReceive);
                thNew.IsBackground = true;
                thNew.Start();
            }

        }
        public void GetReceive() 
        {
            while (true)
            {
                byte[] byts = new byte[1024 * 1024 * 5];
                int r = socketCommunicate.Receive(byts);
                txtGetMsg.AppendText(socketCommunicate.RemoteEndPoint.ToString() + "  " + Encoding.Default.GetString(byts, 0, r) + "\n");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
            comboBox1.Items.Add("所有人");
            comboBox1.SelectedIndex = 0;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedItem.ToString() == "所有人")
            {
                for (int i = 0; i < list.Count; i++)
                {
                    byte[] byts = Encoding.Default.GetBytes(txtSendMsg.Text);
                    List<byte> listByte = byts.ToList();
                    listByte.Insert(0, 0);
                    byts = listByte.ToArray();
                    list[i].Send(byts);
                }
            }
            else 
            {
                byte[] byts = Encoding.Default.GetBytes(txtSendMsg.Text);
                List<byte> listByte = byts.ToList();
                listByte.Insert(0, 0);
                byts = listByte.ToArray();
                list[comboBox1.SelectedIndex-1].Send(byts);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            openFileDialog1.FileName = "";
            openFileDialog1.InitialDirectory = @"C:\Users\Administrator\Desktop";
            openFileDialog1.Title = "请选择需要打开的文件";
            openFileDialog1.Filter = "所有文件|*.*|文本文件|*.txt|图片|*.jpg";
            openFileDialog1.ShowDialog(this);
            textBox1.Text = openFileDialog1.FileName;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            using (FileStream fsRead = new FileStream(openFileDialog1.FileName, FileMode.OpenOrCreate, FileAccess.Read)) 
            {
                if (comboBox1.SelectedItem.ToString() == "所有人")
                {
                    for (int i = 0; i < list.Count; i++)
                    {
                        byte[] byts = new byte[fsRead.Length];
                        int r = fsRead.Read(byts, 0, byts.Length);
                        List<byte> listByte = byts.ToList();
                        listByte.Insert(0, 1);
                        byts = listByte.ToArray();

                        list[i].Send(byts);
                    }
                }
                else 
                {
                    byte[] byts = new byte[fsRead.Length];
                    int r = fsRead.Read(byts,0,byts.Length);
                    List<byte> listByte = byts.ToList();
                    listByte.Insert(0, 1);
                    byts = listByte.ToArray();

                    list[comboBox1.SelectedIndex - 1].Send(byts);
                }
                int index = openFileDialog1.FileName.LastIndexOf('\\');
                string str = openFileDialog1.FileName.Substring(index + 1);
                txtGetMsg.AppendText("成功发送文件 "+str);
            }
        }

    }
}
