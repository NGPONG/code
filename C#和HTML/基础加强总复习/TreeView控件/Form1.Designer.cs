namespace TreeView控件
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
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("123");
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.button1 = new System.Windows.Forms.Button();
            this.txtParent = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.txtChild = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // treeView1
            // 
            this.treeView1.Location = new System.Drawing.Point(32, 46);
            this.treeView1.Name = "treeView1";
            treeNode1.Name = "节点0";
            treeNode1.Text = "123";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode1});
            this.treeView1.Size = new System.Drawing.Size(164, 238);
            this.treeView1.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(265, 46);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "添加根节点";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // txtParent
            // 
            this.txtParent.Location = new System.Drawing.Point(265, 84);
            this.txtParent.Name = "txtParent";
            this.txtParent.Size = new System.Drawing.Size(131, 21);
            this.txtParent.TabIndex = 2;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(265, 121);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 3;
            this.button2.Text = "添加子节点";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // txtChild
            // 
            this.txtChild.Location = new System.Drawing.Point(265, 163);
            this.txtChild.Name = "txtChild";
            this.txtChild.Size = new System.Drawing.Size(131, 21);
            this.txtChild.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(645, 593);
            this.Controls.Add(this.txtChild);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.txtParent);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.treeView1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox txtParent;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox txtChild;
    }
}

