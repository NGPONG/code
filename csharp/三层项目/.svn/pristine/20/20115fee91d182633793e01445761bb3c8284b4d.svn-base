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
    public class DishTypeInfoBLL
    {
        private DishTypeInfoDAL objClient = new DishTypeInfoDAL();

        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>反序列化后的LIST集合</returns>
        public DataTable GetData()
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.GetData();
                List<DishTypeInfoModel_GetData> listResult = SerializableObject.DeserializeObject<DishTypeInfoModel_GetData>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<DishTypeInfoModel_GetData>(listResult);
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
        ///  检查是否存在相同的用户名
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public DataTable CheckHaveSameDishTitle(DishTypeInfoModel model)
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.CheckHaveSameDishTitle(model);
                List<DishTypeInfoModel_CheckHaveSameDishTitle> listResult = SerializableObject.DeserializeObject<DishTypeInfoModel_CheckHaveSameDishTitle>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<DishTypeInfoModel_CheckHaveSameDishTitle>(listResult);
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
        /// <param name="model"></param>
        /// <returns></returns>
        public int AddDishTypeInfoDetail(DishTypeInfoModel model)
        {
            try
            {
                return this.objClient.AddDishTypeInfoDetail(model);
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
        public int UpdateDishTypeInfoDetail(DishTypeInfoModel model)
        {
            try
            {
                return this.objClient.UpdateDishTypeInfoDetail(model);
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
        public int DeleteDishTypeInfoDetail(DishTypeInfoModel model)
        {
            try
            {
                return this.objClient.DeleteDishTypeInfoDetail(model);
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
