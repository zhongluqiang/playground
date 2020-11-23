#ifndef __MEMDUMP_H__
#define __MEMDUMP_H__

/**
 * @brief 打印一段内存，输出地址、数据和可见字符，可指定数据的显示进制
 * 
 * @param [IN] addr: 内存起始地址
 * @param [IN] size: 内存大小
 * @param [IN] format: 显示进制，2（二进制），8（八进制），10（十进制），16（十六进制）
 * 
 * @retval 无
 */
void memdump(const void *addr, unsigned long size, int format);

#endif