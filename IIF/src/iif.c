/////////////////////////////////////////////////////////////////////////////////
//
// File name: IIF/iif.c
// The IIF(Integration Interface), it's used to control every interaction between
// modules to make sure the independent between modules. Any direct function call
// between modules will cause the dependency between modules.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hal_module_pub.h>
#include <hal_module2_pub.h>
#include <iif_pub.h>
#include <iif.h>

//iif_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *iif_version="sv#iif_ver:1.0.0+1.1";

//----------------------------------------------------------------------------
//Function Name: IifInit
//Description  : IIF software initialization. Any software related initialization
//               should deploy here such like variable initialization, memory
//               allocation and lower layer's software initialization,etc.
//Param        :
//      1. void *handle: IIF handle's private data.
//      2. none
//      3. none
//return value : True if IIF software initialized correctly or False if it's not.
//----------------------------------------------------------------------------
IifS32 IifInit(void *handle)
{
  IifPrivateData *iif_fd = (IifPrivateData *)handle;

  iif_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  iif_fd->OsalHandle->OsalPrint("======IIF single mode initialization======\n");
  iif_fd->hal_module1_handle->HalModuleInit(iif_fd->hal_module1_handle->fd);


  return IIF_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: IifDeinit
//Description  : IIF software destruction. Any software related destruction
//               should deploy here such like variable clean to default, free the memory
//               and lower layer's software destruction,etc.
//Param        :
//      1. void *handle: IIF handle's private data.
//      2. none
//      3. none
//return value : True if IIF software is destroyed correctly or False if it's not.
//----------------------------------------------------------------------------
IifS32 IifDeinit(void *handle)
{
  IifPrivateData *iif_fd = (IifPrivateData *)handle;

  iif_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  iif_fd->OsalHandle->OsalPrint("======IIF single mode deinitialization======\n");
  iif_fd->hal_module1_handle->HalModuleDeinit(iif_fd->hal_module1_handle->fd);

  return IIF_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: IifMethod1
//Description  : In single mode of IIF this method is doing nothing.
//Param        :
//      1. void *handle: IIF handle's private data.
//      2. none
//      3. none
//return value : True
//----------------------------------------------------------------------------
IifS32  IifMethod1(void *handle){

  IifPrivateData *iif_fd = (IifPrivateData *)handle;

  //iif_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  return IIF_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: IifDualInit
//Description  : IIF software initialization. Any software related initialization
//               should deploy here such like variable initialization, memory
//               allocation and lower layer's software initialization,etc.
//Param        :
//      1. void *handle: IIF handle's private data.
//      2. none
//      3. none
//return value : True if IIF software initialized correctly or False if it's not.
//----------------------------------------------------------------------------
IifS32 IifDualInit(void *handle)
{
  IifPrivateData *iif_fd = (IifPrivateData *)handle;

  iif_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  iif_fd->OsalHandle->OsalPrint("======IIF dual mode initialization======\n");

  iif_fd->hal_module1_handle->HalModuleInit(iif_fd->hal_module1_handle->fd);
  iif_fd->hal_module2_handle->HalModule2Init(iif_fd->hal_module2_handle->fd);

  iif_fd->hal_module1_handle->HalModuleRegisterHalCbMethod1(iif_fd->hal_module1_handle->fd, iif_fd->hal_module2_handle->fd, iif_fd->hal_module2_handle->HalModule2CbMethod);
  iif_fd->hal_module1_handle->HalModuleRegisterISRCbMethod(iif_fd->hal_module1_handle->fd, iif_fd->hal_module2_handle->fd, iif_fd->hal_module2_handle->HalModule2ISRCbMethod);

  return IIF_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: IifDualDeinit
//Description  : IIF software destruction. Any software related destruction
//               should deploy here such like variable clean to default, free the memory
//               and lower layer's software destruction,etc.
//Param        :
//      1. void *handle: IIF handle's private data.
//      2. none
//      3. none
//return value : True if IIF software is destroyed correctly or False if it's not.
//----------------------------------------------------------------------------
IifS32 IifDualDeinit(void *handle)
{
  IifPrivateData *iif_fd = (IifPrivateData *)handle;

  iif_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  iif_fd->OsalHandle->OsalPrint("======IIF dual mode deinitialization======\n");

  iif_fd->hal_module1_handle->HalModuleDeinit(iif_fd->hal_module1_handle->fd);
  iif_fd->hal_module2_handle->HalModule2Deinit(iif_fd->hal_module2_handle->fd);

  return IIF_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: IifDualMethod1
//Description  : IIF is the layer that used to control the flow between two modules.
//               In this example,IIF layer it will call module1's HAL method and
//               in HAL method it will call the module2's call back function to achieve
//               interaction between modules.
//Param        :
//      1. void *handle: IIF handle's private data.
//      2. none
//      3. none
//return value : True if IIF software is destroyed correctly or False if it's not.
//----------------------------------------------------------------------------
IifS32  IifDualMethod1(void *handle){

  IifPrivateData *iif_fd = (IifPrivateData *)handle;

  //iif_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  iif_fd->hal_module1_handle->HalModuleMethod1(iif_fd->hal_module1_handle->fd);

  return IIF_TRUE;
}

