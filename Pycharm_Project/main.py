import fnmatch
import os
# os: 用于文件系统操作，例如遍历目录、获取文件大小等。
# Flask: 用于创建 Web API。
# request: 用于访问传入的 HTTP 请求参数。
# jsonify: 用于将 Python 对象转换为 JSON 格式并返回。
from flask import Flask, request, jsonify

app = Flask(__name__)


def find_files(directory, need=None, pattern=None):
    result = []

    # 使用 os.walk 遍历给定目录及其子目录。
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)

            # 如果指定了文件大小，则只查找大于或等于该大小的文件。
            if need is not None:
                if os.path.getsize(file_path) < need:
                    continue

            # 如果指定了文件名模式，则只查找符合该模式的文件。
            if pattern is not None:
                if not fnmatch.fnmatch(file, pattern):
                    continue

            # 将符合条件的文件路径添加到 result 列表中，并最终返回这个列表。
            result.append(file_path)

    return result


# 通过 GET 请求访问该 API。
# 提供三个查询参数：
# directory: 必须提供，指定查找的根目录。
# size_mb: 可选，指定查找的最小文件大小（MB）。
# pattern: 可选，指定文件名的匹配模式（例如 *.xml 匹配所有 .xml 文件）。
@app.route('/find', methods=['GET'])
def find():
    directory = request.args.get('directory')
    size = request.args.get('size_mb', type=float)
    pattern = request.args.get('pattern')

    if not directory:
        return jsonify({'error': '必须提供目录参数'}), 400

    # 将文件大小转换为字节
    min_size = size * 1024 * 1024 if size else None

    # 查找文件
    files = find_files(directory, min_size, pattern)

    return jsonify(files)


if __name__ == '__main__':
    app.run(debug=True)
