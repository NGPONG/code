using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test08
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Demo de = new Demo();
            de.Name = "123";
            de.Age = "1213";

            byte[] buff;
            using (MemoryStream ms1 = new MemoryStream()) 
            {
                BinaryFormatter bf1 = new BinaryFormatter();
                bf1.Serialize(ms1, de);
                buff = ms1.GetBuffer();
            }

            using (MemoryStream ms2 = new MemoryStream(buff)) 
            {
                BinaryFormatter bf2 = new BinaryFormatter();
                Demo de2 = (Demo)(bf2.Deserialize(ms2));
            }
        }
    }
    [Serializable]
    public class Demo 
    {
        public string Name { get; set; }
        public string Age { get; set; }
    }
}
