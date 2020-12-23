namespace 用xml文档实现增删查改
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
            this.components = new System.ComponentModel.Container();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.a = new System.Windows.Forms.Label();
            this.x = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txtAddID = new System.Windows.Forms.TextBox();
            this.txtAddPwd = new System.Windows.Forms.TextBox();
            this.txtAddName = new System.Windows.Forms.TextBox();
            this.txtAddAge = new System.Windows.Forms.TextBox();
            this.rdoAddMan = new System.Windows.Forms.RadioButton();
            this.rdoAddWoman = new System.Windows.Forms.RadioButton();
            this.btnAddOK = new System.Windows.Forms.Button();
            this.zz = new System.Windows.Forms.GroupBox();
            this.btnChangeOK = new System.Windows.Forms.Button();
            this.rdoChangeWoman = new System.Windows.Forms.RadioButton();
            this.txtChangePwd = new System.Windows.Forms.TextBox();
            this.rdoChangeMan = new System.Windows.Forms.RadioButton();
            this.label3 = new System.Windows.Forms.Label();
            this.txtChangeID = new System.Windows.Forms.TextBox();
            this.txtChangeAge = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtChangeName = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.删除ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.zz.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2,
            this.Column3,
            this.Column4,
            this.Column5});
            this.dataGridView1.ContextMenuStrip = this.contextMenuStrip1;
            this.dataGridView1.Location = new System.Drawing.Point(12, 12);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(536, 205);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellClick);
            // 
            // Column1
            // 
            this.Column1.DataPropertyName = "ID";
            this.Column1.HeaderText = "ID";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            // 
            // Column2
            // 
            this.Column2.DataPropertyName = "Name";
            this.Column2.HeaderText = "姓名";
            this.Column2.Name = "Column2";
            this.Column2.ReadOnly = true;
            // 
            // Column3
            // 
            this.Column3.DataPropertyName = "Age";
            this.Column3.HeaderText = "年龄";
            this.Column3.Name = "Column3";
            this.Column3.ReadOnly = true;
            // 
            // Column4
            // 
            this.Column4.DataPropertyName = "Gender";
            this.Column4.HeaderText = "性别";
            this.Column4.Name = "Column4";
            this.Column4.ReadOnly = true;
            // 
            // Column5
            // 
            this.Column5.DataPropertyName = "PassWord";
            this.Column5.HeaderText = "密码";
            this.Column5.Name = "Column5";
            this.Column5.ReadOnly = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnAddOK);
            this.groupBox1.Controls.Add(this.rdoAddWoman);
            this.groupBox1.Controls.Add(this.txtAddPwd);
            this.groupBox1.Controls.Add(this.rdoAddMan);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.txtAddID);
            this.groupBox1.Controls.Add(this.txtAddAge);
            this.groupBox1.Controls.Add(this.x);
            this.groupBox1.Controls.Add(this.txtAddName);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.a);
            this.groupBox1.Location = new System.Drawing.Point(54, 236);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(163, 251);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "新增";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(17, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "姓名";
            // 
            // a
            // 
            this.a.AutoSize = true;
            this.a.Location = new System.Drawing.Point(6, 98);
            this.a.Name = "a";
            this.a.Size = new System.Drawing.Size(29, 12);
            this.a.TabIndex = 2;
            this.a.Text = "年龄";
            // 
            // x
            // 
            this.x.AutoSize = true;
            this.x.Location = new System.Drawing.Point(6, 139);
            this.x.Name = "x";
            this.x.Size = new System.Drawing.Size(29, 12);
            this.x.TabIndex = 3;
            this.x.Text = "密码";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 186);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(29, 12);
            this.label5.TabIndex = 4;
            this.label5.Text = "性别";
            // 
            // txtAddID
            // 
            this.txtAddID.Location = new System.Drawing.Point(41, 14);
            this.txtAddID.Name = "txtAddID";
            this.txtAddID.Size = new System.Drawing.Size(100, 21);
            this.txtAddID.TabIndex = 1;
            // 
            // txtAddPwd
            // 
            this.txtAddPwd.Location = new System.Drawing.Point(41, 136);
            this.txtAddPwd.Name = "txtAddPwd";
            this.txtAddPwd.Size = new System.Drawing.Size(100, 21);
            this.txtAddPwd.TabIndex = 2;
            // 
            // txtAddName
            // 
            this.txtAddName.Location = new System.Drawing.Point(41, 53);
            this.txtAddName.Name = "txtAddName";
            this.txtAddName.Size = new System.Drawing.Size(100, 21);
            this.txtAddName.TabIndex = 3;
            // 
            // txtAddAge
            // 
            this.txtAddAge.Location = new System.Drawing.Point(41, 95);
            this.txtAddAge.Name = "txtAddAge";
            this.txtAddAge.Size = new System.Drawing.Size(100, 21);
            this.txtAddAge.TabIndex = 4;
            // 
            // rdoAddMan
            // 
            this.rdoAddMan.AutoSize = true;
            this.rdoAddMan.Location = new System.Drawing.Point(41, 184);
            this.rdoAddMan.Name = "rdoAddMan";
            this.rdoAddMan.Size = new System.Drawing.Size(47, 16);
            this.rdoAddMan.TabIndex = 6;
            this.rdoAddMan.TabStop = true;
            this.rdoAddMan.Text = "先生";
            this.rdoAddMan.UseVisualStyleBackColor = true;
            // 
            // rdoAddWoman
            // 
            this.rdoAddWoman.AutoSize = true;
            this.rdoAddWoman.Location = new System.Drawing.Point(94, 184);
            this.rdoAddWoman.Name = "rdoAddWoman";
            this.rdoAddWoman.Size = new System.Drawing.Size(47, 16);
            this.rdoAddWoman.TabIndex = 7;
            this.rdoAddWoman.TabStop = true;
            this.rdoAddWoman.Text = "女士";
            this.rdoAddWoman.UseVisualStyleBackColor = true;
            // 
            // btnAddOK
            // 
            this.btnAddOK.Location = new System.Drawing.Point(41, 217);
            this.btnAddOK.Name = "btnAddOK";
            this.btnAddOK.Size = new System.Drawing.Size(100, 23);
            this.btnAddOK.TabIndex = 8;
            this.btnAddOK.Text = "注册";
            this.btnAddOK.UseVisualStyleBackColor = true;
            this.btnAddOK.Click += new System.EventHandler(this.btnAddOK_Click);
            // 
            // zz
            // 
            this.zz.Controls.Add(this.btnChangeOK);
            this.zz.Controls.Add(this.rdoChangeWoman);
            this.zz.Controls.Add(this.txtChangePwd);
            this.zz.Controls.Add(this.rdoChangeMan);
            this.zz.Controls.Add(this.label3);
            this.zz.Controls.Add(this.txtChangeID);
            this.zz.Controls.Add(this.txtChangeAge);
            this.zz.Controls.Add(this.label4);
            this.zz.Controls.Add(this.txtChangeName);
            this.zz.Controls.Add(this.label6);
            this.zz.Controls.Add(this.label7);
            this.zz.Controls.Add(this.label8);
            this.zz.Location = new System.Drawing.Point(347, 236);
            this.zz.Name = "zz";
            this.zz.Size = new System.Drawing.Size(160, 251);
            this.zz.TabIndex = 2;
            this.zz.TabStop = false;
            this.zz.Text = "修改";
            // 
            // btnChangeOK
            // 
            this.btnChangeOK.Location = new System.Drawing.Point(41, 217);
            this.btnChangeOK.Name = "btnChangeOK";
            this.btnChangeOK.Size = new System.Drawing.Size(100, 23);
            this.btnChangeOK.TabIndex = 8;
            this.btnChangeOK.Text = "修改";
            this.btnChangeOK.UseVisualStyleBackColor = true;
            this.btnChangeOK.Click += new System.EventHandler(this.btnChangeOK_Click);
            // 
            // rdoChangeWoman
            // 
            this.rdoChangeWoman.AutoSize = true;
            this.rdoChangeWoman.Location = new System.Drawing.Point(94, 184);
            this.rdoChangeWoman.Name = "rdoChangeWoman";
            this.rdoChangeWoman.Size = new System.Drawing.Size(47, 16);
            this.rdoChangeWoman.TabIndex = 7;
            this.rdoChangeWoman.TabStop = true;
            this.rdoChangeWoman.Text = "女士";
            this.rdoChangeWoman.UseVisualStyleBackColor = true;
            // 
            // txtChangePwd
            // 
            this.txtChangePwd.Location = new System.Drawing.Point(41, 136);
            this.txtChangePwd.Name = "txtChangePwd";
            this.txtChangePwd.Size = new System.Drawing.Size(100, 21);
            this.txtChangePwd.TabIndex = 2;
            // 
            // rdoChangeMan
            // 
            this.rdoChangeMan.AutoSize = true;
            this.rdoChangeMan.Location = new System.Drawing.Point(41, 184);
            this.rdoChangeMan.Name = "rdoChangeMan";
            this.rdoChangeMan.Size = new System.Drawing.Size(47, 16);
            this.rdoChangeMan.TabIndex = 6;
            this.rdoChangeMan.TabStop = true;
            this.rdoChangeMan.Text = "先生";
            this.rdoChangeMan.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 186);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 12);
            this.label3.TabIndex = 4;
            this.label3.Text = "性别";
            // 
            // txtChangeID
            // 
            this.txtChangeID.Location = new System.Drawing.Point(41, 14);
            this.txtChangeID.Name = "txtChangeID";
            this.txtChangeID.Size = new System.Drawing.Size(100, 21);
            this.txtChangeID.TabIndex = 1;
            // 
            // txtChangeAge
            // 
            this.txtChangeAge.Location = new System.Drawing.Point(41, 95);
            this.txtChangeAge.Name = "txtChangeAge";
            this.txtChangeAge.Size = new System.Drawing.Size(100, 21);
            this.txtChangeAge.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 139);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(29, 12);
            this.label4.TabIndex = 3;
            this.label4.Text = "密码";
            // 
            // txtChangeName
            // 
            this.txtChangeName.Location = new System.Drawing.Point(41, 53);
            this.txtChangeName.Name = "txtChangeName";
            this.txtChangeName.Size = new System.Drawing.Size(100, 21);
            this.txtChangeName.TabIndex = 3;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(18, 17);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(17, 12);
            this.label6.TabIndex = 0;
            this.label6.Text = "ID";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 53);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(29, 12);
            this.label7.TabIndex = 1;
            this.label7.Text = "姓名";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(6, 98);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(29, 12);
            this.label8.TabIndex = 2;
            this.label8.Text = "年龄";
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.删除ToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(101, 26);
            // 
            // 删除ToolStripMenuItem
            // 
            this.删除ToolStripMenuItem.Name = "删除ToolStripMenuItem";
            this.删除ToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.删除ToolStripMenuItem.Text = "删除";
            this.删除ToolStripMenuItem.Click += new System.EventHandler(this.删除ToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(569, 532);
            this.Controls.Add(this.zz);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.zz.ResumeLayout(false);
            this.zz.PerformLayout();
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column4;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column5;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtAddID;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label a;
        private System.Windows.Forms.Label x;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtAddAge;
        private System.Windows.Forms.TextBox txtAddName;
        private System.Windows.Forms.TextBox txtAddPwd;
        private System.Windows.Forms.Button btnAddOK;
        private System.Windows.Forms.RadioButton rdoAddWoman;
        private System.Windows.Forms.RadioButton rdoAddMan;
        private System.Windows.Forms.GroupBox zz;
        private System.Windows.Forms.Button btnChangeOK;
        private System.Windows.Forms.RadioButton rdoChangeWoman;
        private System.Windows.Forms.TextBox txtChangePwd;
        private System.Windows.Forms.RadioButton rdoChangeMan;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtChangeID;
        private System.Windows.Forms.TextBox txtChangeAge;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtChangeName;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 删除ToolStripMenuItem;
    }
}

