def iou(box1, box2):
    x1 = max(box1[0], box2[0])
    y1 = max(box1[1], box2[1])
    x2 = min(box1[2], box2[2])
    y2 = min(box1[3], box2[3])

    width = max(0, x2 - x1 + 1)
    height = max(0, y2 - y1 + 1)

    intersection = width * height

    area1 = (box1[2] - box1[0] + 1) * (box1[3] - box1[1] + 1)
    area2 = (box2[2] - box2[0] + 1) * (box2[3] - box2[1] + 1)
    iou = intersection / float(area1 + area2 - intersection)

    return iou

def nms(boxes, scores, iou_threshold):
    order = sorted(range(len(scores)), key=lambda k: scores[k], reverse=True)
    keep = []
    while order:
        i = order.pop(0)
        keep.append(i)
        filtered_order = []
        for t in order:
            if iou(boxes[i], boxes[t]) <= iou_threshold:
                filtered_order.append(t)
        order = filtered_order
    result = keep
    return 1

boxes = [
    [0, 0, 100, 100],
    [0, 0, 50, 50],
    [100, 100, 200, 200],
]
scores = [0.8, 0.75, 0.75]
iou_threshold = 0.2

kept_indices = nms(boxes, scores, iou_threshold)
print("保留的框的编号：", kept_indices)
