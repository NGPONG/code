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
    public class TableInfoBLL
    {
        private TableInfoDAL objClient = new TableInfoDAL();

        /// <summary>
        ///  获取数据
        /// </summary>
        /// <returns>反序列化后的LIST集合</returns>
        public DataTable GetData()
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.GetData();
                List<TableInfoModel_GetData> listResult = SerializableObject.DeserializeObject<TableInfoModel_GetData>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<TableInfoModel_GetData>(listResult);
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
        ///  检查是否存在相同的厅堂或包间名称
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public DataTable CheckHaveSameTableTitle(TableInfoModel model)
        {
            try
            {
                List<byte[]> listSerializeBuff = this.objClient.CheckHaveSameTableTitle(model);
                List<TableInfoModel_CheckHaveSameTableTitle> listResult = SerializableObject.DeserializeObject<TableInfoModel_CheckHaveSameTableTitle>(listSerializeBuff);
                DataTable dtResult = ConvertWP.ToDataTable<TableInfoModel_CheckHaveSameTableTitle>(listResult);
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
        public int AddTableInfoDetail(TableInfoModel model)
        {
            try
            {
                return this.objClient.AddTableInfoDetail(model);
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
        public int UpdateTableInfoDetail(TableInfoModel model)
        {
            try
            {
                return this.objClient.UpdateTableInfoDetail(model);
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
        ///  修改使用状态
        /// </summary>
        /// <param name="model"></param>
        /// <returns></returns>
        public int UpdateTableInfoState(TableInfoModel model)
        {
            try
            {
                return this.objClient.UpdateTableInfoState(model);
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
        public int DeleteTableInfoDetail(TableInfoModel model)
        {
            try
            {
                return this.objClient.DeleteTableInfoDetail(model);
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
