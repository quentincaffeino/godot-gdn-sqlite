
# GDNSQLite


#### Member Functions

| Methods | Description |
|--|--|
| *Variant* execute(*string* query, *Array* parameters) | Execute query with given parameters. |
| *Variant* executeRaw(*string* query) | Execute raw query. |


#### Example

```gdscript
db.execute('SELECT * FROM container WHERE id = ?', [34])
db.executeRaw('SELECT * FROM container WHERE id = 34')
```
