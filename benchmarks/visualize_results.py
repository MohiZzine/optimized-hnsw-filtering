import pandas as pd
import matplotlib.pyplot as plt
import json
import sys

def create_visualizations(json_file):
    # Read data
    with open(json_file) as f:
        data = json.load(f)

    # Process into DataFrame
    records = []
    for benchmark in data['benchmarks']:
        name_parts = benchmark['name'].split('/')
        method = name_parts[0]
        test_type = name_parts[1]
        size = int(name_parts[2])
        records.append({
            'Method': test_type.replace('FilterSingle', '').replace('FilterMulti', ''),
            'Type': 'Single' if 'Single' in test_type else 'Multi',
            'Size': size,
            'Time_us': benchmark['cpu_time'],
            'Throughput': benchmark['items_per_second'],
            'Scenario': benchmark['label']
        })

    df = pd.DataFrame(records)

    # Create figure with subplots
    fig, axes = plt.subplots(2, 2, figsize=(15, 12))
    fig.suptitle('Filter Performance Comparison', fontsize=16)

    # 1. Comparison of Methods (Top Left)
    avg_times = df.groupby(['Method', 'Type'])['Time_us'].mean().unstack()
    avg_times.plot(kind='bar', ax=axes[0,0])
    axes[0,0].set_title('Average Time by Method')
    axes[0,0].set_ylabel('Time (microseconds)')
    axes[0,0].grid(True)
    
    # 2. Throughput Comparison (Top Right)
    throughput = df.groupby(['Method', 'Type'])['Throughput'].mean().unstack()
    throughput.plot(kind='bar', ax=axes[0,1])
    axes[0,1].set_title('Throughput by Method')
    axes[0,1].set_ylabel('Items per Second')
    axes[0,1].grid(True)

    # 3. Single vs Multi Query (Bottom Left)
    single_multi = pd.pivot_table(df, values='Time_us', 
                                index='Method', 
                                columns='Type', 
                                aggfunc='mean')
    single_multi.plot(kind='bar', ax=axes[1,0])
    axes[1,0].set_title('Single vs Multi Query Performance')
    axes[1,0].set_ylabel('Time (microseconds)')
    axes[1,0].grid(True)

    # 4. Method Performance by Size (Bottom Right)
    for method in df['Method'].unique():
        data = df[df['Method'] == method]
        axes[1,1].plot(data['Size'], data['Time_us'], 
                      marker='o', label=method)
    axes[1,1].set_title('Performance vs Size')
    axes[1,1].set_xlabel('Size')
    axes[1,1].set_ylabel('Time (microseconds)')
    axes[1,1].grid(True)
    axes[1,1].legend()

    # Adjust layout and save
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.savefig('benchmark_comparison.png', dpi=300, bbox_inches='tight')

    # Generate numerical summary
    summary = pd.DataFrame({
        'Mean Time (μs)': df.groupby(['Method', 'Type'])['Time_us'].mean(),
        'Mean Throughput (items/s)': df.groupby(['Method', 'Type'])['Throughput'].mean(),
        'Min Time (μs)': df.groupby(['Method', 'Type'])['Time_us'].min(),
        'Max Time (μs)': df.groupby(['Method', 'Type'])['Time_us'].max(),
    }).round(2)
    
    summary.to_csv('benchmark_summary.csv')
    print("\nBenchmark Summary:")
    print(summary)
    print("\nResults saved as benchmark_comparison.png and benchmark_summary.csv")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python visualize_results.py results.json")
        sys.exit(1)
    create_visualizations(sys.argv[1])