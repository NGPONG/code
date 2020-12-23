namespace WP.Demo.UI
{
    partial class frmDishInfo
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.btnRemove = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            this.btnAddType = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.ddlTypeAdd = new System.Windows.Forms.ComboBox();
            this.txtChar = new System.Windows.Forms.TextBox();
            this.txtPrice = new System.Windows.Forms.TextBox();
            this.txtTitleSave = new System.Windows.Forms.TextBox();
            this.txtId = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.dgvList = new System.Windows.Forms.DataGridView();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.ddlTypeSearch = new System.Windows.Forms.ComboBox();
            this.btnSearchAll = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.txtTitleSearch = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.dgvtxtDId = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvtxtdTitle = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvtxtDTypeTitle = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvtxtDPrice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvtxtDChar = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dgvList)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "名  称：";
            // 
            // btnRemove
            // 
            this.btnRemove.Location = new System.Drawing.Point(13, 282);
            this.btnRemove.Name = "btnRemove";
            this.btnRemove.Size = new System.Drawing.Size(167, 23);
            this.btnRemove.TabIndex = 16;
            this.btnRemove.Text = "删除选中的行数据";
            this.btnRemove.UseVisualStyleBackColor = true;
            this.btnRemove.Click += new System.EventHandler(this.btnRemove_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.ForeColor = System.Drawing.Color.Red;
            this.label9.Location = new System.Drawing.Point(9, 262);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(149, 12);
            this.label9.TabIndex = 15;
            this.label9.Text = "提示：双击表格项进行修改";
            // 
            // btnAddType
            // 
            this.btnAddType.Location = new System.Drawing.Point(58, 119);
            this.btnAddType.Name = "btnAddType";
            this.btnAddType.Size = new System.Drawing.Size(122, 23);
            this.btnAddType.TabIndex = 13;
            this.btnAddType.Text = "分类管理";
            this.btnAddType.UseVisualStyleBackColor = true;
            this.btnAddType.Click += new System.EventHandler(this.btnAddType_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(105, 226);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 12;
            this.btnCancel.Text = "取消";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(11, 226);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(72, 23);
            this.btnSave.TabIndex = 11;
            this.btnSave.Text = "添加";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // ddlTypeAdd
            // 
            this.ddlTypeAdd.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ddlTypeAdd.FormattingEnabled = true;
            this.ddlTypeAdd.Location = new System.Drawing.Point(58, 92);
            this.ddlTypeAdd.Name = "ddlTypeAdd";
            this.ddlTypeAdd.Size = new System.Drawing.Size(122, 20);
            this.ddlTypeAdd.TabIndex = 10;
            // 
            // txtChar
            // 
            this.txtChar.Location = new System.Drawing.Point(58, 186);
            this.txtChar.Name = "txtChar";
            this.txtChar.Size = new System.Drawing.Size(122, 21);
            this.txtChar.TabIndex = 9;
            // 
            // txtPrice
            // 
            this.txtPrice.Location = new System.Drawing.Point(58, 155);
            this.txtPrice.Name = "txtPrice";
            this.txtPrice.Size = new System.Drawing.Size(122, 21);
            this.txtPrice.TabIndex = 8;
            // 
            // txtTitleSave
            // 
            this.txtTitleSave.Location = new System.Drawing.Point(58, 57);
            this.txtTitleSave.Name = "txtTitleSave";
            this.txtTitleSave.Size = new System.Drawing.Size(122, 21);
            this.txtTitleSave.TabIndex = 6;
            this.txtTitleSave.TextChanged += new System.EventHandler(this.txtTitleSave_TextChanged);
            // 
            // txtId
            // 
            this.txtId.Location = new System.Drawing.Point(58, 24);
            this.txtId.Name = "txtId";
            this.txtId.ReadOnly = true;
            this.txtId.Size = new System.Drawing.Size(122, 21);
            this.txtId.TabIndex = 5;
            this.txtId.Text = "添加时无编号";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(11, 194);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(53, 12);
            this.label7.TabIndex = 4;
            this.label7.Text = "拼  音：";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(11, 159);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(53, 12);
            this.label6.TabIndex = 3;
            this.label6.Text = "价  格：";
            // 
            // dgvList
            // 
            this.dgvList.AllowUserToAddRows = false;
            this.dgvList.AllowUserToDeleteRows = false;
            this.dgvList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dgvtxtDId,
            this.dgvtxtdTitle,
            this.dgvtxtDTypeTitle,
            this.dgvtxtDPrice,
            this.dgvtxtDChar});
            this.dgvList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dgvList.Location = new System.Drawing.Point(3, 17);
            this.dgvList.MultiSelect = false;
            this.dgvList.Name = "dgvList";
            this.dgvList.ReadOnly = true;
            this.dgvList.RowTemplate.Height = 23;
            this.dgvList.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvList.Size = new System.Drawing.Size(548, 428);
            this.dgvList.TabIndex = 0;
            this.dgvList.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgvList_CellDoubleClick);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(11, 95);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(53, 12);
            this.label5.TabIndex = 2;
            this.label5.Text = "分  类：";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.dgvList);
            this.groupBox1.Location = new System.Drawing.Point(12, 9);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(554, 448);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "列表";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(11, 61);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 12);
            this.label4.TabIndex = 1;
            this.label4.Text = "名  称：";
            // 
            // ddlTypeSearch
            // 
            this.ddlTypeSearch.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ddlTypeSearch.FormattingEnabled = true;
            this.ddlTypeSearch.Location = new System.Drawing.Point(58, 57);
            this.ddlTypeSearch.Name = "ddlTypeSearch";
            this.ddlTypeSearch.Size = new System.Drawing.Size(122, 20);
            this.ddlTypeSearch.TabIndex = 8;
            this.ddlTypeSearch.SelectedIndexChanged += new System.EventHandler(this.ddlTypeSearch_SelectedIndexChanged);
            // 
            // btnSearchAll
            // 
            this.btnSearchAll.Location = new System.Drawing.Point(13, 94);
            this.btnSearchAll.Name = "btnSearchAll";
            this.btnSearchAll.Size = new System.Drawing.Size(167, 23);
            this.btnSearchAll.TabIndex = 5;
            this.btnSearchAll.Text = "显示全部";
            this.btnSearchAll.UseVisualStyleBackColor = true;
            this.btnSearchAll.Click += new System.EventHandler(this.btnSearchAll_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 61);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "分  类：";
            // 
            // txtTitleSearch
            // 
            this.txtTitleSearch.Location = new System.Drawing.Point(57, 18);
            this.txtTitleSearch.Name = "txtTitleSearch";
            this.txtTitleSearch.Size = new System.Drawing.Size(123, 21);
            this.txtTitleSearch.TabIndex = 1;
            this.txtTitleSearch.TextChanged += new System.EventHandler(this.txtTitleSearch_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(9, 30);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 0;
            this.label3.Text = "编  号：";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.btnRemove);
            this.groupBox3.Controls.Add(this.label9);
            this.groupBox3.Controls.Add(this.btnAddType);
            this.groupBox3.Controls.Add(this.btnCancel);
            this.groupBox3.Controls.Add(this.btnSave);
            this.groupBox3.Controls.Add(this.ddlTypeAdd);
            this.groupBox3.Controls.Add(this.txtChar);
            this.groupBox3.Controls.Add(this.txtPrice);
            this.groupBox3.Controls.Add(this.txtTitleSave);
            this.groupBox3.Controls.Add(this.txtId);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Location = new System.Drawing.Point(572, 140);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(189, 317);
            this.groupBox3.TabIndex = 12;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "添加\\修改";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.ddlTypeSearch);
            this.groupBox2.Controls.Add(this.btnSearchAll);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.txtTitleSearch);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Location = new System.Drawing.Point(572, 9);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(189, 125);
            this.groupBox2.TabIndex = 11;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "搜索";
            // 
            // dgvtxtDId
            // 
            this.dgvtxtDId.DataPropertyName = "Did";
            this.dgvtxtDId.HeaderText = "编号";
            this.dgvtxtDId.Name = "dgvtxtDId";
            this.dgvtxtDId.ReadOnly = true;
            // 
            // dgvtxtdTitle
            // 
            this.dgvtxtdTitle.DataPropertyName = "DTitle";
            this.dgvtxtdTitle.HeaderText = "名称";
            this.dgvtxtdTitle.Name = "dgvtxtdTitle";
            this.dgvtxtdTitle.ReadOnly = true;
            // 
            // dgvtxtDTypeTitle
            // 
            this.dgvtxtDTypeTitle.DataPropertyName = "DTypeTitle";
            this.dgvtxtDTypeTitle.HeaderText = "分类";
            this.dgvtxtDTypeTitle.Name = "dgvtxtDTypeTitle";
            this.dgvtxtDTypeTitle.ReadOnly = true;
            // 
            // dgvtxtDPrice
            // 
            this.dgvtxtDPrice.DataPropertyName = "DPrice";
            this.dgvtxtDPrice.HeaderText = "价格";
            this.dgvtxtDPrice.Name = "dgvtxtDPrice";
            this.dgvtxtDPrice.ReadOnly = true;
            // 
            // dgvtxtDChar
            // 
            this.dgvtxtDChar.DataPropertyName = "DChar";
            this.dgvtxtDChar.HeaderText = "拼音";
            this.dgvtxtDChar.Name = "dgvtxtDChar";
            this.dgvtxtDChar.ReadOnly = true;
            // 
            // frmDishInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(771, 465);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.MaximizeBox = false;
            this.Name = "frmDishInfo";
            this.ShowIcon = false;
            this.Text = "菜品管理";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmDishInfo_FormClosing);
            this.Load += new System.EventHandler(this.frmDishInfo_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvList)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnRemove;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button btnAddType;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.ComboBox ddlTypeAdd;
        private System.Windows.Forms.TextBox txtChar;
        private System.Windows.Forms.TextBox txtPrice;
        private System.Windows.Forms.TextBox txtTitleSave;
        private System.Windows.Forms.TextBox txtId;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.DataGridView dgvList;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox ddlTypeSearch;
        private System.Windows.Forms.Button btnSearchAll;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtTitleSearch;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvtxtDId;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvtxtdTitle;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvtxtDTypeTitle;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvtxtDPrice;
        private System.Windows.Forms.DataGridViewTextBoxColumn dgvtxtDChar;
    }
}