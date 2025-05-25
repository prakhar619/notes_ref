## Part I. Foundations of Data System
# Chapter 3: Storage and Retrieval

Storage Engine   
A level deeper than before  

#### Storage File Format
0. Basic Append-Only
    - Write: Append data/line in a file
    - Read: Read the whole file to get the required data

1. Better Append-Only
    - Data Segment and **Compaction**
    - Data segment store all new key-value, old key-value (no update).
    - Create Data segment and close it/save it when it reaches certain size.
    - Create new Data segment and start writing in it.
    - For Read, start reading from latest data segment, if found then return else open previous data segment
    - Compaction: Merge multiple data segment to store latest value to key and create a new segment with that. Discard all previous data segment.
    - For Deletion use Tombstone (special instruction to look no further)
    - One writer thread, multiple reader threads

1.  SSTables 
    - String Sorted Table
    - Introduced in Google's BigTable paper
    - Keep Data segment sorted
    - Only one key in one data segment; (meaning update key in same data segment)
    - Create new data segment when it reaches certain size.
    - Compaction: Merge 2 sorted data segment to create new data segment. Discard all previous data segment. Keep value of key present in latest data segment.
    - **Pro**: Indexing now easy and more compact as it can store sparse data and scan data between that to get exact record. Like ha.. and he.. so we know hc will lie between them.
    - **Optimisation**: 
        - Size-Tiered: Small and newer sstables are successively merged into older and larger sstables
        - Leveled-Compaction: :Used by LevelDB and RocksDB

#### Data Structure
1. B-Trees 
    - Most widely used indexing structure
    - Standard index implementation in all relational database and many non relational db too.
    - Database is broken down into fixed-size blocks or page
    - Block size: 4KB
    - Read-Write 1 Page at a time
    - One Page/Block is Root.
    - Each page contains keys and reference to child pages.
    - Leaf Page: Either contain value of each key(inline) or a reference to its location.
    - Branching Factor: No of Reference on each page.
    - Eg of Page: |*ref* 100 *ref* 200 *ref* 300 *ref* 400 *ref* 500 *ref*|
    - Writing: Add a key: Find the page and add. If page is full. Break the page into parts. Add a new page and new page child will be broken part of previous page.
    - 4 level tree of 4KB with branching factor of 500 can store 256TB of data.
    - **Pro**: Most time data is overwritten at same place.
    - *WAL*: Write Ahead Log (append only log) for preventing data loss when splitting page into part and if db crashed.
    - *Copy on write Scheme*: Instead of WAL, create new version of parent page somewhere else and point the pointer to new location.
    - Addition pointer introduction to point to sibling pages
    - Lot of fragmentation



### Storage Engine Architecture
1. Log-Structured Storage Engine
    1. LSM Tree
        - Log Structured Merge Tree
        - Use SST method to build the foundation.
        - Use Tree structure (Balanced BST) to store keep data in memory.
        - When size reaches threshold then flush it into a data segment.
        - Read: Read first in memory data structure, then latest data segment then older.
        - Time-to-Time run compaction queries in background to combine segment files and discard older data segment.
        - ***Memtable***: In-Memory tree
        - **Con**: Accidental failure can cause data loss in RAM -> Keep separate log for each write. Discard when flushing into data segment.
        - LevelDB, RocksDB, Cassandra and HBase
        - **Optimization**: Bloom Filter: Memory-Efficient data structure for approximating content of set for efficient ops and tells if key does not appear in database.
        - Less fragmentation

2. Page-Oriented Storage Engine
    - B Tree usage


LSM-Trees are typically faster of writes, B-Trees are faster of reads.

**Write Amplification**: One write to database causes multiple writes in disk.

### Indexes
An additional data structure that is derived from the primary data.   
Only affects the performance of queries.  
**Trade-off**: Well-Chosen indexes speed up read queries but every index slows down writes.

Application developer need to choose indexes manually based on which type of queries will be used.

Types:
1. Hash Indexes 
    - Simplest
    - In-memory hash map keeping key - byteOffset of each record.
    - Append and Update operations
    - Bitcask Storage Engine (Storage Engine of Riak)
    - **Con**: Hash map need to fit in memory (RAM); System restart causes data loss

2. Lucene 
    - Indexing Engine 
    - For Full-text search
    - in-memory index

Secondary Indexes 
- Can be contructed from key-value index
- Keys may not be unique
- Both B-Tree and Log-structured indexes can be used as secondary indexes

Values in Index
- Can be either actual row (document, vertex) or reference/pointer to somewhere else
    - Heap Index
        - Heap File: When value is reference/pointer to row present somewhere else; Avoid data duplication
        - Heap Con: When updating file, changes size to larger; All pointer needs to be updated
    - Clustered Index 
        - Storing indexed row directly within an index
        - Usually done with Primary index
    - Covering Index/ Index with Included columns
        - Middle ground between heap and clustered indexing

Multi-Column Indexes 
- Concatenated Index
    - Most common type of multi-column index
    - Useless when filtering required on multiple columns
- R-Trees
    - Specialized Spatial Indexes
    - PostGIS

MySQL and InnoDB:
Clustered Primary Index with Secondary Index pointing to Primary Key

**Memcached**: In-memory Databases  
VoltDB, MemSQL, Oracle TimesTen are relational in-memory databases.  
RAMCloud in open source in memory database.
- Very Fast
- RAM is getting cheaper
- Power Outage is reducing
- Reduce overhead of encoding for writing to disk
- **Anti-Caching**: Evicting least used data into disk when not enough memory

## Transaction Processing or Analytics

Transaction processing vs Batch processing jobs  
- Transaction processing means allowing clients to make low latency reads and writes 
- Batch Processing jobs are run periodically, usually associated with large data

### OLTP vs OLAP
-  **O**n**l**ine **T**ransaction **P**rocessing: for Transaction Processing
    - Main Write Pattern: Random-access low latency writes from user input
    - Main Read Pattern: Small number of records per query, fetched by key
    - Primary Usage By: Customer/End user
    - Dataset size: GB to TB
- **O**n**l**ine **A**nalytics **P**rocessing: for Batch Processing
    - Main Write Pattern: Bulk import (ETL) or event Stream
    - Main Read Pattern: Aggregate over large number of records
    - Primary Usage By: Internal Analyst for decision support
    - Dataset size: TB to PB

Earlier single database was expected to run both OLAP and OLTP-type queries, but in 1980s and 90s, companies shifted to different database for OLAP, *data warehouse*.

#### Data Warehousing 
- OLTP databases needs to be highly available and have low latency to process transactions.  
- DB Admin were reluctant to let BAs run ad-hoc analytic queries on an OLTP database.  
- Data is extracted from OLTP databases (periodic dump or continous steam of updates), transformed into an analytics-friendly schema, cleaned-up and then loaded into data warehouse. *ETL* (Extract-Load-Transform).
- Indexing described in first part works well for OLTP queries but are not great for OLAP type queries.
- OLTP database can be NOSQL or SQL, but OLAP DB are usually SQL based.
- Even Relational OLTP and OLAP are quite different from inside as both uses different indexing techniques.
- OLAP + OLTP: Microsoft SQL Server, SAP Hana.
- OLAP (Datawarehouse): Teradata, Vertica, SAP Hana,  ParAccel. (redshift is a hosted version of ParAccel).
- Open Source Datawarehouse: Apache Hive, Spark SQL, Cloudera Impala, Facebook Persto, Apache Tajo and Apache Drill. (Based on Google's **Dremel**);

#### Schema for Analytics
Star vs Snowflakes Schema   
1. Star Schema
    - Also called Dimensional Modeling
    - At centre: Fact Table
    - Around: Dimensional Table 
2. Snowflakes Schema
    - Dimensional Data are split into subdimensions
    - More normalized than Star Schema
    
#### Column-Oriented Storage
1. OLTP db storage is laid out in row-oriented fashion.
2. Dont store all values from one row together but store all values for each column togethor instead.
3. Each column is stored in a separate file.
4. **Column Compression**: 
    - If a colunn takes only handful of distinct values we could create a map to link bit values to original values and use the bit values
    - Like Column1: Product1, Product2, Product3, Product1, Product3
    - Compressed:   0001,     00010,   0100,      0001,   0100
5. **Run-Length Encoding**:
    - Compressed Column bit values can be further be encoded in space efficient manner
    - Like Column1: 0000_0001, 0000_0010, 0010_0100, ...
    - Run Encoded: 7:1, 6:1, 2:1:2      (#zeros: #ones: #zeros: #ones) (exclude last zeros)
6. For datawarehousing queries, big bottleneck is bandwidth for getting data from disk into memory, also worry about using bandwidth from main memory into CPU cache. Column compression techniques help a lot here.
7. Vectorized Processing in Datawarehousing: ?
8. Sorting: Keep data in sorted order, order based on which type of queries (which column) is filtered on.
9. Sorting helps in column compression as run-length can be applied on column lvl.
10. Compression effect is strongest on the first sort key.
11. **C-Store**: When creating a copy of data for redundancy, keep data sorted on different column. When needed use different copies for different type of queries.
12. Writing: 
    - Difficult to write optimized indexers because of sorted order.
    - Update-in-place approach (Like B-trees) difficult.
    - Use LSM Trees: Write in-memory, (sorted order), Then periodically flush.
    - Vertica does this.

#### Data Cube and Materialized View
1. Creating cache for different type of data queries is called materialized view.
2. Materialized view is actual copy of data.
3. Needs to be updated when base data is changed.
4. Special case of Materialized view: **Data Cube** or **OLAP Cube**.
5. Data Cube:
    - Simple Case: 2d Cube with x-axis as 1D (may be products) and y-axis another dimension (may be time)
    - Each entry is aggreagation of metric like spend. 
    - For each product and time we have aggreage spend.
    - Can be filter easily.
    - Extend Simple case to include multiple dimesion.
    - Con: Only helps with Metrics (numbers)
    - Con: Cant help to filter data based on metrics (like Spend > 20 on single transaction).

### Summary:
> OLTP: Disk Seek time is bottleneck  
> OLAP: Disk Bandwidth is bottleneck  
> OLTP: 2 Storage Engine Type
>   1. Log Structured School:   
>       - Only permits appending and delete obsolete files
>       - Never updates a file that has been written.
>       - Eg: BitCask, SSTables, LSM-Trees, LevelDB, Cassandrea, HBase, Lucene
>   2. Update-in-place School:
>       - Treats disk as fixed size pages that can be overwritten
>       - B-Trees


Storage and Query Engine









