import hashlib

# Define the message to be hashed
message = "Hello, world!"

# Create a SHA-256 hash object
hash_object = hashlib.sha256()

# Update the hash object with the message
hash_object.update(message.encode())

# Get the hexadecimal representation of the hash value
hex_dig = hash_object.hexdigest()

# Print the hash value
print()
print("The hashed value of the message is:", hex_dig)
print()
print("length of the output for SHA-256 algorithm:", len(hex_dig)*4, "bits")
print()
print("The block size of hashed value:", hash_object.block_size)
print()

## NOTE: Every time I run it, I get the same value (property of hash functions)