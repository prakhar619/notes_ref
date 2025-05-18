## Part I. Foundations of Data System
# Chapter 2: Data Models and Query Languages 

It can take a lot of effort to master just one data model.
### Data Models

- Relational Model vs Document Model
  - Relational Model 
    - Data is organized into relations called tables
    - Eg MySQL
    - Lasted 25-30 years (eternity in Computing History)
    - Roots lie in Business Data Processing (transaction processing and batch invoice processing)
    - Query Optimizers: Best part of Relational model, are very complicated and tooks years of development.
    - Schema on write
    - Schema changes are slow and require downtime.
    - Real world data structure, influenced by external system, may change any time.
    - For data locality: Google's Spanner DB allows table's rows interleaved with parent table
    - Oracle uses *multi-table index cluster tables* for locality
    - **Column-Family** concept  in BigTable Data model (used in *Cassandra* and *HBase*)
    - **Network Model** and **Heirarchical Model**, early competition to relational model in 70s and 80s.
  - NoSQL 
    - Not Only SQL 
    - Catchy Hashtag of Twitter in 2009.
  - Heirachical Model 📖
    - IBM Information Management System (IMS) was based on this.
    - JSON similarity
    - Easy Many - One relationship, difficult Many - Many relationship
    - No Joins
    - Either duplicate the data or manually reference the data from one to other
    - Hierachical Tree Structure, every record has exactly one parent.
  - Network Model 📖
    - Standardized by CODASYL (Conference on Data Systems Languages)
    - Also called CODASYL Model
    - Generalization of Hierachical Model
    - In Network Tree Structure, record can have multiple parents.
    - Links b/w records are not foreign keys but pointers like C.
    - **Access Path**: Follow a path from a root record along these links.
    - Application code had to keep track of all parent each record had.
    - Quering and update was difficult because of access path.
    - Very flexible
  - Document Model 
    - Flexible Schema, Better performance due to locality
    - If you data is document type: Use document model.
    - **Shredding**: Splitting document-like structure into multiple tables
    - Poor join support
    - Bad Many-Many relationship
    - Access Path like relationship
    - Schema on read
    - Single Continous string, encoded as JSON, XML or binary variant like MongDB BSON
    - Avoid overwriting a record with larger record.
    - Data Locality major benefit.

**Facebook Graph Model**  
Facebook maintain single graph with differenty types of vertices and edges  
Vertices represent: 
- People
- Location
- Event
- Checkins
- Comment

Edges represent:
- which people are friends
- which checkin happened in which loc
- who commented on which post
- who attented which event

**Polyglot Persistence**: Relational database will continue to be used alongside a broad variety of non-relational datastores.

**Object-Relational Mismatch** or **Impedance Mismatch**:   
- Application Layer: Object Oriented   
- Data Model: Relational.  
- Awakward translation layer is required b/w the objects.
- ORM (Object-Relational Mapping) frameworks like *ActiveRecord* and *Hibernate* reduce boilerplate code

Many - Many Mapping 
1. Traditional SQL: Normalized representation. Each normalized table with foreign link linking to main table. Many-Many Relationships
2. SQL standard have added support for structured datatype such as XML and JSON. Check with different product/vendors like Oracle, IBM, MS SQL for these support
3. Encode these values as JSON/XML and put as text in text column in database.

JSON 
- Better representation for Object Oriented data structures
- Better locality
- Schema Less, or Schema on read

> Best is hybrid model: Using Relationship model with Built in support for document model/locality.
>> IBM DB2 (relational model): support JSON documents  
>> RethinkDB (document model): support join in its query language

### Data Languages

- Imperative Query Language
  - IMS and CODASYL
  - tells the computer to perform certain operations in certain order
  - hard to parallelize as operations specified requires ordering
- Declarative Query Language
  - SQL
  - specify the pattern of data you want
  - lot of room for internal optimisation
  - parallel execution
  - CSS and XSL are declarative (although not data languages)
**MapReduce Quering**  
Popularised by Google  
Used for Processing large amount of data in bulk across multiple machines  
It's a logic/algorithm  
Based on Map (also called collect) and Reduce (also called fold/inject)
Fairly low-level programming model


### Graph-Like Data Models
Many-Many relationship handling  
Can be social graphs, web graphs, road-rail networks  
Page Rank algorithm can work on graph models (specially web graph) for ranking page popularity.

Graph Data Models
1. Property Graph Model
    - Neo4j, Titan and InfiniteGraph
    - Think of 2 relational tables, one for vertices and one for edges
    - Vertex consists of 
      - Unique Identifier
      - Set of outgoing edges
      - Set of incoming edges
      - Collection of Properties (key-value pairs)
    - Edge consists of 
      - Unique Identifier
      - Vertex at which edge starts
      - Vertex at which edge ends
      - Label to describe the relationship
      - Collection of Properties (key-value pairs)
2. Triple-Store Model
	- Datomic, Allegro Graph
	- Simple 3 part statment (subject, predicate, object)
	- Subject is equivalent to vertex
	- Object can one of 2 things
		- Value in a primitive datatype
		- Another vertex in the graph, and then predicate is edge, (subject: tail vertex, object: head vertex)
	- Eg: Normat Format: 
		- Subject -> _:lucy, ...
		- Predicate -> a, :name, :type, ...
		- Object -> "Lucy", _:idaho, ...
		```
			@prefix : <urn:example:>.
			_:lucy a :Person.
			_:lucy :name "Lucy".
			_:lucy :bornIn _:idaho.
			_:idaho a :Location.
			_:idaho :name "Idaho".
			_:idaho :type "state".
			_:idaho :within _:usa.
			_:usa a :Location.
			_:usa :name "United States".
			_:usa :type "country".
			_:usa :within _:namerica.
			_:namerica a :Location.
			_:namerica :name "North America".
			_:namerica :type "continent".
		```
	- Eg: Turtle Format for compact queries
		- \<Subject> \<predicate> \<object>; \<predicate> \<object>; \<predicate> \<object>.
		```
			@prefix : <urn:example:>
			_:lucy a :Person; :name "Lucy"; :bornIn _:idaho.
			_:idaho a :Location; :name "Idaho"; :type "state"; :within _:usa.
			_:usa a :Location; :name "United States"; :type "country"; :within _:namerica.
			_:namerica a :Location; :name "North America"; :type "continent".
		```

Graph Query Languages
1. Declarative Query Language
	- Cypher 
		- Neo4j graph database
		- Create Record
			```
			CREATE
			(NAmerica:Location {name:'North America', type:'continent'}),
			(USA:Location {name:'United States', type:'country' }),
			(Idaho:Location {name:'Idaho', type:'state' }),
			(Lucy:Person {name:'Lucy' }),
			(Idaho) -[:WITHIN]-> (USA) -[:WITHIN]-> (NAmerica),
			(Lucy) -[:BORN_IN]-> (Idaho)
			```
		- Query Record
			```
			MATCH
			(person) -[:BORN_IN]-> () -[:WITHIN*0..]-> (us:Location {name:'United States'}),
			(person) -[:LIVES_IN]-> () -[:WITHIN*0..]-> (eu:Location {name:'Europe'})
			RETURN person.name
			```
	- SPARQL 
		- Query Language for triple-stores using RDF data model 
		- Pronounced Sparkle
		- SPARQL Protocol and RDF Query Language 
	- Datalog 
2. Imperative QL 
    - Gremlin 
3. Graph Processing Framework 
    - Pregel

**SQL for Graph**  
Can be done but with some difficult  
Requires Recursive CTEs

**Semantic Web**  
Simple Idea: Website already publish information as text and pictures for humans.  
Why dont we publish information as machine-readable data for computer to read.

**RDF**  
Resource Description Framework  
mechanism for different website to publish data in a consistent format to be able combine data into *web of data*
Turtle Language, as well as some code in XML format
```
<rdf:RDF xmlns="urn:example:"
xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#">
<Location rdf:nodeID="idaho">
<name>Idaho</name>
<type>state</type>
<within>
<Location rdf:nodeID="usa">
<name>United States</name>
<type>country</type>
<within>
<Location rdf:nodeID="namerica">
<name>North America</name>
<type>continent</type>
</Location>
</within>
</Location>
</within>
</Location>
<Person rdf:nodeID="lucy">
<name>Lucy</name>
<bornIn rdf:nodeID="idaho"/>
</Person>
</rdf:RDF>
```

**Graph Database vs CODASYL**  
CODASYL is a network data model   
1. IN CODASYL, database had a schema that specified which record type could be nested with other record. In Graph DB no such restriction
2. No Access Path in graph db as each vertex as Unique Id
3. IN CODASYL, childen of a record were ordered, no such ordering in graph db
4. CODASYL was imperative. Although graph db is also imperative at low level, they support high level declarative query language such as Cypher and SPARQL.


### Datalog
Generalising triple-store model   
(Subject, Predicate, Object) -> Predicate(Subject, Object)  
Eg:   
1. Write
	```
	name(namerica, 'North America').
	type(namerica, continent).

	name(usa, 'United States').
	type(usa, country).
	within(usa, namerica).

	name(idaho, 'Idaho').
	type(idaho, state).
	within(idaho, usa).

	name(lucy, 'Lucy').
	born_in(lucy, idaho).
	```
2. Query 
	```
	within_recursive(Location, Name) :- name(Location, Name). /* Rule 1 */
	within_recursive(Location, Name) :- within(Location, Via), /* Rule 2 */
										within_recursive(Via, Name).
	migrated(Name, BornIn, LivingIn) :- name(Person, Name), /* Rule 3 */
										born_in(Person, BornLoc),
										within_recursive(BornLoc, BornIn),
										lives_in(Person, LivingLoc),
										within_recursive(LivingLoc, LivingIn).
	```
	- First Define rules that tell database about new predicates and querying technique.
	- Built complex queries from simple ones.


### Summary 
> Chech which type of data model to use  
> Check which query language to use  
> Which operation will you be doing on database  




> Specialised Data Models:   
> GenBank

> Specialised Ops:  
> Full-text Search

> 