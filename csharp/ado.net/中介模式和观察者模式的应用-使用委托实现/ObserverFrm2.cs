﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 中介模式和观察者模式的应用_使用委托实现
{
    public partial class ObserverFrm2 : Form
    {
        public ObserverFrm2()
        {
            InitializeComponent();
        }

        public void GetMsgFrm2(string str) 
        {
            this.textBox1.Text = str;
        }
    }
}
