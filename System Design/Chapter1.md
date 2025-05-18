## Part I. Foundations of Data System
# Chapter 1: Reliable, Scalable and Maintainable Applications

Systems are now Data-Intensive, as opposed to Compute-Intensive

Memcached:  Application-Managed Caching Layer
Full-Text Search Server: ElasticSearch or Solr

3 concerns that are important in most software systems:  
1. Reliability
2. Scalability
3. Maintainability

### Reliability:

- Fault vs Failure    
  - Fault is when system deviating from its spec whereas failure denotes system as whole stops (no service)

- Netflix Chaos Monkey
  - Software that Neflix uses to terminate random virtual machines to check robustness and reliability
    
- Hardware Faults 
  - Hard-disk: Mean time to failure of about 10-50 years
        Solution: Redundancy 

  **Larger Number of Machines -> Increased Rate of Hardware Failure**

- Software Errors
  - May be weakly correlated with Hardware
  - Usually correlated error therefore multiple devices affected
  - Cascading Failure 
  - Bug may lie dormant for a long time 

- Human Errors 
  - Configuration errors are most common reason for downtime
  
> Fixes 
>1. Decouple things  
>2. Sandbox environment 
>3. Automated testing, not only all part of code but all edge cases
>4. Roll back Configurations ready
>5. Telemetry: Detailed and clear monitoring

### Scalability 
 
Load can be described with a few numbers which we call **load parameters**. Best choice of parameters depend upon system's architecture.

- Batch processing system - Hadoop , cares about 'Throughput'.

- Response time vs Latency 
  - Latency is time taken to process the request whereas response time is total time to get a response.

- Percentile Response Time
  - If a response time like 3ms is 95 percentile, meaning out of 100, 95 requests have response time less then 3ms.
  - p95, p99, p999 are 95 percentile, 99 percentile and 99.9 percentile 
  - High Percentile of response times also called **tail latencies** are important. Amazon uses p999.
- SLOs and SLAs
    - Service Level Objective (SLOs) and Service level Agreements (SLAs) are contracts that define the expected performance and availiability of a service. [Refund if aimed objective of response time/service not met]
- Head-of-line Blocking 
    - Due to limited parallelism and queuing of request, it takes only small number of slow requests to hold up the processing requests.
- When generating load artificially, load generating client needs to keep sending requests independently of response time.
- Tail latency Amplification
  - Backend service that are called multiple times as part of serving single end-user request, slowest parallel call decide response time, and chance of slow call increases and higher proportion of end-user requests end up being slow.
  
- Metrics for Monitoring
  - Keeping list of all requests' response time within the time window and to sort that list every minute ---> Too inefficient
  - Use algorithms like forward decay, t-digest or HdrHistogram, good approximation of percentiles.

> Approaches of Coping Load
>>1. Scaling up and Scaling out 
>>  - Scaling up: Vertical Scaling, More powerful machine  
>>  - Scaling out/Shared-Nothing : Horizontal Scaling, Distributing load across multiple machines  
>>2. Using elastic system, which can automatically add / remove computing resource when they detect load increase.
>>3. Stateless service are easy to scale out, and always try to keep database on single node (scaled up) until you are forced to do different.
>>4. No magic scaling sauce, every architecture need different scalable solution


### Maintainability

Three Design Principles for Software Systems

1. Operability
2. Simplicity
3. Evolvability/Plasticity/Modifiability/Extensibility

#### Operability 

Monitoring health of system, quickly restoring service, tracking issues, update latest firmware, latest security patches, managing configuration changes, setting good practices for deployemnt etc

#### Simplicity 

Explosion of state space, tight coupling modules, tangled dependencies, inconsistent naming and terminology, special-casing to work -> Increases complexity

> Ues Abstraction to remove complexity.

#### Evolvability 

Agile Software Development: Framework for adapting to changes.
Principles: 
- Individuals and interactions over processes and tools
- Working software over comprehensive documentation
- Customer collaboration over contract negotiation
- Responding to change over following a plan








