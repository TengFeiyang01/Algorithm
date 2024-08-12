SELECT 
    sid,
    cid,
    score,
    ROW_NUMBER() OVER (PARTITION BY cid ORDER BY score DESC, sid ASC) AS ranking
FROM 
    grade_tb
WHERE 
    ROW_NUMBER() OVER (PARTITION BY cid ORDER BY score DESC, sid ASC) <= 3
ORDER BY 
    cid ASC,
    ranking ASC;
