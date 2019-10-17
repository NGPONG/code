using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Entity;
using System.Data.Entity.Infrastructure;

namespace EF_SimpleCRUD
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void BtnAdd_Click(object sender, EventArgs e)
        {
            using (EFDemoEntities db = new EFDemoEntities())
            {
                // 每次使用实体类通过EF对数据进行添加操作的时候，都会为自动的为我们返回当前所操作的实体类的在添加完毕数据后的主键的ID的值，其原理是因为EF在生成SQL的时候，在插入数据后还会查询出当前查数据后的最后的主键ID的值（该字段是主键并且有标识规范的话）

                // 直接操作EF针对模型所缓存的实体集进行添加数据
                CustomerSet customer = new CustomerSet()
                {
                    CustomerName = "EF 数据添加测试2",
                    CustomerAddress = "深圳龙华"
                };
                var local = db.CustomerSet.Local;
                db.CustomerSet.Add(customer);
                db.SaveChanges();


                // 把实体的实例添加到EF所缓存的实体集当中，并且标记其状态为添加
                CustomerSet customer1 = new CustomerSet()
                {
                    CustomerName = "EF 数据添加测试4",
                    CustomerAddress = "深圳龙华"
                };
                db.Entry<CustomerSet>(customer1).State = EntityState.Added;
                db.SaveChanges();

                // 把实体的实例添加到EF所缓存的实体集当中，并且标记其状态为添加
                CustomerSet customer2 = new CustomerSet()
                {
                    CustomerName = "EF 数据添加测试5",
                    CustomerAddress = "深圳龙华"
                };
                db.CustomerSet.Attach(customer2);
                db.SaveChanges();
            }
        }

        private void BntDelete_Click(object sender, EventArgs e)
        {
            using (EFDemoEntities db = new EFDemoEntities())
            {
                // 查询出对应的实体并把它放在本地缓存的实体集当中，在根据查询出来的实体从本地缓存的实体集中删除，并同步至数据库的修改
                var customer = (from c in db.CustomerSet
                                where c.CustomerId == 2
                                select c).FirstOrDefault();
                db.CustomerSet.Remove(customer);
                db.SaveChanges();


                // 把实体的实例添加到EF所缓存的实体集当中，并且标记其状态为删除
                // 当我们所自己创建的实体的实例在数据库中无法找到对应的数据，使用该方法就会报错
                // 把所添加的实体标记为删除，区别于remove，所标记的实体的实例就算不是ef查询出来的也不会报错，因为Entry函数的操作会把参数放到所对应的dbcontext该表所对应的实体集当中去，因为已经添加了，所以dbcontext该表所对应的实体集是有数据的，所以删除就不会报错了
                var customer2 = new CustomerSet()
                {
                    CustomerId = 5
                };
                db.Entry(customer2).State = EntityState.Deleted;
                db.SaveChanges();
            }
        }

        private void BtnSearch_Click(object sender, EventArgs e)
        {
            using (EFDemoEntities db = new EFDemoEntities())
            {
                db.Database.CreateIfNotExists();
                var query = from c in db.CustomerSet
                            where c.CustomerId == 4
                            select c.CustomerName;

                MessageBox.Show(string.Join("&&",query.ToArray()));
            }
        }

        private void BtnUpdate_Click(object sender, EventArgs e)
        {
            using (EFDemoEntities db = new EFDemoEntities())
            {
                // 取消EF对于实体完整性的检查
                db.Configuration.ValidateOnSaveEnabled = false;
                CustomerSet customer = new CustomerSet()
                {
                    CustomerId = 9
                };
                CustomerSet customer1 = db.CustomerSet.Attach(customer);
                customer1.CustomerName = "Update CustomerName";
                db.SaveChanges();
            }
        }
    }
}
