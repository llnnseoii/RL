# UK EQ-5D-5L Realistic QALY Reward PPO

Reinforcement Learning project for colorectal cancer screening policy optimization using realistic health economics-based rewards.

## Key Features

- **UK EQ-5D-5L Population Norms**: 17 age groups with gender-specific health utility weights
- **Realistic Reward Structure**: `R = -Cost + QALY_gain - Mortality_cost`
- **Health Economics Framework**: 
  - Actual Korean colonoscopy costs ($917-$1,205)
  - Cancer treatment costs by stage
  - QALY value: $50,000 (Korean WTP threshold)
  - Life expectancy-based mortality costs

## Files

- `ppo_realistic_qaly.py` - PPO training with UK EQ-5D-5L rewards
- `qaly_calculator_updated.py` - QALY calculator with gender-specific values
- `verify_eq5d.py` - Data verification script
- `cql_optimizer.py` - CQL offline RL optimizer
- `run_quality_pipeline.py` - Complete training pipeline
- `evaluate_cql.py` - Policy evaluation

## Data Sources

- **EQ-5D-5L**: UK population norms (Szende et al., 2014)
- **Cancer Utilities**: Teckle et al., 2015
- **Costs**: Korean evaluation.ini data
- **Life Expectancy**: Korean Statistics 2023

## Usage

### Train PPO with Realistic Rewards
```bash
python ppo_realistic_qaly.py
```

### Verify EQ-5D Data
```bash
python verify_eq5d.py
```

### Train CQL
```bash
python run_quality_pipeline.py
```

### Evaluate Policy
```bash
python evaluate_cql.py
```

## Reward Structure

```python
R = -C_test - C_followup + QALY_gain - Mortality_cost

# Components:
# - C_test: Colonoscopy cost ($917-$1,205)
# - QALY_gain: Age/gender-specific utility × $50,000
# - Mortality_cost: Lost life years × discounted QALY value
```

## EQ-5D-5L Values

| Age Group | Female | Male |
|-----------|--------|------|
| 50-54 | 0.798 | 0.836 |
| 60-64 | 0.776 | 0.803 |
| 70-74 | 0.784 | 0.801 |

*Full 17 age groups with linear interpolation*

## Author

llnnseoii

## License

MIT
