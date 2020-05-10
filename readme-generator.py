#!/usr/bin/env python3
# Created by @BugenZhao https://github.com/BugenZhao
# Modified by @MinoZhao
import json
import requests
import os
import re
import pprint
from requests.exceptions import Timeout 
difficulties = [None, '😊', '🤨', '😫']

questions = None
try:
    with open('questions.json', 'r') as fp:
        questions = json.load(fp)
except:
    url = 'https://leetcode.com/api/problems/algorithms/'
    try:
        print("Starting")
        r = requests.get(url, timeout=10)
    except Timeout:
        print("request failed !")
        exit()
    questions = json.loads(r.content)['stat_status_pairs']
    questions.sort(key=lambda e: e['stat']['frontend_question_id'])
    with open('questions.json', 'w') as fp:
        json.dump(questions, fp)

lines = []
solved = {}


def findAllFile(base):
    for root, ds, fs in os.walk(base):
        for f in fs:
            if f.endswith('.py') or f.endswith('.cpp'):
                fullname = os.path.join(root, f)
                yield [f, fullname]

dirpath = '.'
for group in findAllFile(dirpath):
    file_name = group[0]
    file_path = group[1]
    #print("file_name = ", file_name)
    qid = re.findall(r"^\d*", file_name)
    if qid[0] == '':
        continue
    file_path = file_path.replace(' ', '%20')
    print("file_path = ", repr(file_path))
    print("pid = ", int(qid[0]))
    solved[int(qid[0])] = file_path

for question in questions:
    qid = question['stat']['frontend_question_id']
    difficulty = difficulties[question['difficulty']['level']]
    title = question['stat']['question__title']
    title_slug = question['stat']['question__title_slug']
    if qid in solved:
        line = '- [X] {} [[Q]](https://leetcode.com/problems/{}/) [[S]]({}) {:0>4d}. {}\n' \
            .format(difficulty, title_slug, solved[qid], qid, title)
    else:
        line = '- [ ] {} [[Q]](https://leetcode.com/problems/{}/) ~~[S]~~  {:0>4d}. {}\n' \
            .format(difficulty, title_slug, qid, title)
    lines.append(line)

with open('README.md', 'w') as fp:
    fp.write('# LeetCode\n')
    fp.write("Yimin's LeetCode solutions.\n")
    fp.write('## Problems\n')
    fp.writelines(lines)
