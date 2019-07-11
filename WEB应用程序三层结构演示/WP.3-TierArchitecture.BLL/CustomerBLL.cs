using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WP._3_TierArchitecture.DAL;

namespace WP._3_TierArchitecture.BLL
{
    public class CustomerBLL
    {
        private CustomerDAL objCustomerDAL = new CustomerDAL();

        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>查询后的结果内存表</returns>
        public DataTable GetData() 
        {
            return this.objCustomerDAL.GetData();
        }
        /// <summary>
        ///  添加数据
        /// </summary>
        /// <returns>受影响的行数</returns>
        public int AddDetail(Dictionary<string, string> dicCustomerInfo)
        {
            return this.objCustomerDAL.AddDetail(dicCustomerInfo);
        }
        /// <summary>
        ///  删除数据
        /// </summary>
        /// <returns>受影响的行数</returns>
        public int DeleteDetail(int ID)
        {
            return this.objCustomerDAL.DeleteDetail(ID);
        }
        /// <summary>
        ///  修改数据
        /// </summary>
        /// <param name="dicCustomerInfo">参数集</param>
        /// <returns>受影响的行数</returns>
        public int UpdateDetail(Dictionary<string, string> dicCustomerInfo) 
        {
            return this.objCustomerDAL.UpdateDetail(dicCustomerInfo);
        }

    }
}
