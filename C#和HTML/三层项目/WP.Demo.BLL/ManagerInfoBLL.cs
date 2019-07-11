using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WP.Demo.Common;
using WP.Demo.DAL;
using WP.Demo.Model;

namespace WP.Demo.BLL
{
    public class ManagerInfoBLL
    {
        private ManagerInfoDAL objClient = new ManagerInfoDAL();

        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>反序列化后的LIST集合</returns>
        public DataTable GetData() 
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.GetData();
                List<ManagerInfoModel_GetData> listResult = SerializableObject.DeserializeObject<ManagerInfoModel_GetData>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<ManagerInfoModel_GetData>(listResult);
                return dtResult;
            }
            catch (Exception objException) 
            {
                if (objException.InnerException != null) 
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  添加数据
        /// </summary>
        /// <param name="MName">用户名</param>
        /// <param name="MPwd">密码</param>
        /// <param name="MType">类型</param>
        /// <returns>受影响的行数</returns>
        public int AddManagerInfoDetail(ManagerInfoModel model) 
        {
            try
            {
                return this.objClient.AddManagerInfoDetail(model);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  修改数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int UpdateManagerInfoDetail(ManagerInfoModel model) 
        {
            try
            {
                return this.objClient.UpdateManagerInfoDetail(model);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  删除数据
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int DeleteManagerInfoDetail(ManagerInfoModel model) 
        {
            try
            {
                return this.objClient.DeleteManagerInfoDetail(model);
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  检查是否存在相同的用户名
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public DataTable CheckHaveSameUserName(ManagerInfoModel model) 
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.CheckHaveSameUserName(model);
                List<ManagerInfoModel_CheckHaveSameUserName> listResult = SerializableObject.DeserializeObject<ManagerInfoModel_CheckHaveSameUserName>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<ManagerInfoModel_CheckHaveSameUserName>(listResult);
                return dtResult;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  获取用户名的密码
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public bool GetUserPassWord(ManagerInfoModel model,string MPwd,out string _tag) 
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.GetUserPassWord(model);
                List<ManagerInfoModel_GetUserPassWord> listResult = SerializableObject.DeserializeObject<ManagerInfoModel_GetUserPassWord>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<ManagerInfoModel_GetUserPassWord>(listResult);

                _tag = "0"; // 默认为员工权限
                if (dtResult != null && dtResult.Rows.Count>0)
                {
                    _tag = ConvertWP.ToTrimString(dtResult.Rows[0]["MType"]);

                    string MPwd_Result = ConvertWP.ToTrimString(dtResult.Rows[0]["MPwd"]);
                    if (MPwd_Result != MPwd)
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
                else 
                {
                    return false;
                }
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
    }
}
