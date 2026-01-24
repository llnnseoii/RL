from cmost_env import CmostEnv

env = CmostEnv()
obs, _ = env.reset()

print("초기 상태:", obs)

for _ in range(10):
    # 랜덤 행동 (0:대기, 1:FOBT, 2:내시경)
    action = env.action_space.sample() 
    obs, reward, done, _, info = env.step(action)
    
    print(f"행동: {action}, 보상: {reward:.1f}, 종료: {done}")
    if done:
        print("에피소드 종료:", info)
        break