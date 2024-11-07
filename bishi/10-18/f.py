def find_files_larger_than_5mb(file):
    large_files = []
    # 查找大于5mb的文件
    # 首先保证当前传入的是一个目录
    if file.isDirectory():
        # 是目录就遍历所有的文件
        for subfile in file.listDirectory():
            # 递归查找
            large_files.extend(find_files_larger_than_5mb(subfile))
    elif file.getSize() > 5 * 1024 * 1024:  # 大于5MB
        # 是文件的话，判断是否大于5mb
        large_files.append(file.getName())
    return large_files


def find_xml_files(file):
    xml_files = []
    # 查找 .xml 的文件
    # 首先保证当前传入的是一个目录
    # 其他地方同上 只不过查询条件变了
    if file.isDirectory():
        for subfile in file.listDirectory():
            xml_files.extend(find_xml_files(subfile))
    elif file.getName().endswith('.xml'):
        xml_files.append(file.getName())
    return xml_files

