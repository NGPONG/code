namespace 连接字符串创建器
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.btnGetString = new System.Windows.Forms.Button();
            this.propSqlConnection = new System.Windows.Forms.PropertyGrid();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // btnGetString
            // 
            this.btnGetString.Location = new System.Drawing.Point(12, 12);
            this.btnGetString.Name = "btnGetString";
            this.btnGetString.Size = new System.Drawing.Size(198, 68);
            this.btnGetString.TabIndex = 0;
            this.btnGetString.Text = "创建连接字符串";
            this.btnGetString.UseVisualStyleBackColor = true;
            this.btnGetString.Click += new System.EventHandler(this.btnGetString_Click);
            // 
            // propSqlConnection
            // 
            this.propSqlConnection.Location = new System.Drawing.Point(216, 12);
            this.propSqlConnection.Name = "propSqlConnection";
            this.propSqlConnection.Size = new System.Drawing.Size(387, 610);
            this.propSqlConnection.TabIndex = 1;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 86);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(198, 536);
            this.textBox1.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(615, 634);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.propSqlConnection);
            this.Controls.Add(this.btnGetString);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnGetString;
        private System.Windows.Forms.PropertyGrid propSqlConnection;
        private System.Windows.Forms.TextBox textBox1;
    }
}

