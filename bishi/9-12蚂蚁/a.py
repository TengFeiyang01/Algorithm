import math
import ast

def calculate_behavior_scores(users_data):
    users_data = ast.literal_eval(users_data)
    # 用于存放结果的字典
    scores = {}
    
    all_clicks = [user['clicks'] for user in users_data.values()]
    all_durations = [user['duration'] for user in users_data.values()]
    all_purchases = [user['purchases'] for user in users_data.values()]

    min_clicks, max_clicks = min(all_clicks), max(all_clicks)
    min_duration, max_duration = min(all_durations), max(all_durations)
    min_purchases, max_purchases = min(all_purchases), max(all_purchases)
    
    for user_id, data in users_data.items():
        normalized_clicks = (data['clicks'] - min_clicks) / (max_clicks - min_clicks) if max_clicks != min_clicks else 0
        normalized_duration = (data['duration'] - min_duration) / (max_duration - min_duration) if max_duration != min_duration else 0
        normalized_purchases = (data['purchases'] - min_purchases) / (max_purchases - min_purchases) if max_purchases != min_purchases else 0
        print(normalized_clicks, normalized_duration, normalized_purchases)
        sum_normalized_purchases = sum(range(1, int(normalized_purchases) + 1))
        

        score = math.log(1 + normalized_clicks) + math.exp(normalized_duration) + sum_normalized_purchases

        scores[user_id] = {'score': round(score, 3)}
    
    return scores

# 示例输入

# 计算并打印用户行为得分
behavior_scores = calculate_behavior_scores(input())
print(behavior_scores)
